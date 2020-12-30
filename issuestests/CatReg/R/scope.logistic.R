
#' Computes solution for SCOPE logistic models
#'
#' @description Computes solution for SCOPE logistic models, computing along a path and iterating local quadratic approximations at each point. Performs K-fold cross-validation
#' for regularisation parameter lambda and can incorporate both linear and categorical (including logical) variables. This function uses a Proximal Newton algorithm and is not guaranteed to converge. It is
#' recommended for developer use only.


#' @param x Data frame of covariates: Can include a mix of continuous and categorical variables (no scaling of continuous covariates is performed within the program).
#' By default an intercept will be added to the linear part; see include_intercept
#' @param y Response vector of length n
#' @param gamma Concavity parameter in MCP; see Zhang (2010) Nearly unbiased estimation with minimax concave penalty
#' @param lambda If NULL default sequence will be generated. Matrix of values (p_categorical times nlambda) of penalty parameter lambda. Must be strictly positive and each row decreasing
#' @param nlambda Length of default sequence of lambda values generated if lambda = NULL
#' @param lambda_min_ratio Ratio of largest to smallest value on default sequence of lambda values
#' @param nfolds Number of folds in cross-validation. If nfolds = 1, no cross-validation is performed
#' @param include_intercept If TRUE, a column of 1s will be added to the (continuous) design matrix
#' @param return_full_beta If TRUE with cross-validation, the entire solution path will be returned instead of just the optimal point
#' @param max_iter Maximum number of iterations at each local quadratic approximation
#' @param max_out_iter Maximum number of local quadratic approximations at each value of lambda
#' @param early_stopping Early stopping based on information criterion. By default is TRUE if there are more than 1 categorical variables
#' @param early_stopping_rounds Number of iterations that information criterion must have not decreased for to terminate
#' @param early_stopping_criterion If "AIC", Akaike Information Criterion is used for early stopping. Otherwise if a positive number is given, modified Bayes Information Criterion is used with this integer as the parameter (CITE)
#' @param noise_variance If noise variance is known, this will be used for scaling the default values of lambda. Otherwise this will be scaled automatically
#' @param terminate_eps Epsilon for convergence criterion, is multiplied by null deviance to get terminate criterion for objective value
#' @param silent If FALSE then progress updates will be printed as solutions are computed. Useful for tuning and diagnosing convergence issues.
#' @param only_cross_validate If TRUE then cross-validation scores for each value of lambda will be returned, but not the estimates themselves
#' @param grid_safe As the automatically generated sequence of lambda values is adjusted during the first fold but fixed thereafter. For subsequent folds, this sets computation to begin at a larger value of lambda to ensure that the first solution along the path is zero so as to maintain the advantages of the pathwise approach. This specifies how many larger values of lambda should be used
#' @param block_order By default the order in block coordinate descent is randomly sampled. Alternatively a permutation vector can be included here
#' @param fold_assignment By default the assignments for cross-validation are randomly sampled automatically. Alternatively assignments can be included here
#' @param zero_penalty Fits unpenalised logistic regression model. Used for testing purposes only.


#'
#' @return A list of objects. Some may not be returned depending on value of arguments K, simply.cross.validated, return.full.beta.
#' \itemize{
#' \item lambda - A matrix of the values of lambda used to compute the solution path. Columns correspond to different points on the path, rows correspond to the categorical
#' variables. Lambda is scaled depending on the number of categories present in the data.
#' \item cverrors - Provided nfolds > 1 then the cross-validation error for each point on the grid will be returned
#' \item beta.full - Contains full solution path. If nfolds > 1 then will only be returned if simply.cross.validated = FALSE and return.full.beta = TRUE. First object [[ 1 ]] is
#' coefficients of continuous variables, [[ 2 ]] is a list of coefficients for categorical variables
#' \item beta.best - Contains solution at CV-optimal point. Requires nfolds > 1 to be returned. This must not be NULL in order to use predict.scope. First object [[ 1 ]] is coefficients of
#' continuous variables, [[ 2 ]] is a list of coefficients for categorical variables
#' \item fold.assign - Contains fold assignments for cross-validation
#' }
#' 
#' @examples
#' \dontrun{
#' x = UniformDesignMatrix(200, 5, 5)
#' y = (as.integer(x[ , 1 ]) < 3) + rnorm(200)
#' y = as.integer(y > 0.8)
#' scope_mod = scope.logistic(x, y)
#' x_new = UniformDesignMatrix(10, 5, 5)
#' predict(scope_mod, x_new)
#' }
#' @export


scope.logistic = function ( x, y, gamma = 8, lambda = NULL, nlambda = 100, lambda_min_ratio = 0.01, nfolds = 5, include_intercept = TRUE, return_full_beta = FALSE,
                            max_iter = 1000, max_out_iter = 1000, early_stopping = ifelse(pshrink > 1, TRUE, FALSE), early_stopping_rounds = 20, early_stopping_criterion = "AIC", noise_variance = NULL, 
                            terminate_eps = 1e-7, silent = TRUE, only_cross_validate = FALSE, grid_safe = 10, block_order = NULL, fold_assignment = NULL, zero_penalty = FALSE) { 


  # y is response vector, xlinear is numeric matrix of covariates that will just be used for the unpenalized linear part of the regression
  # xshrink is a factor data frame where each column corresponds to a categorical variable, categories are numbered 1, 2, 3, ...
  inv.logit = function ( x ) return(exp(x) / ( 1 + exp(x) ))

  logit = function( x ) return(log( x / ( 1 + x )))
  # Important note is that we need to have no empty categories in 1, ..., c_j; if there are any empty ones in advance then ensure that
  # relabelling is performed before calling scope otherwise we'll get errors 
  scopemod = list()
  attr(scopemod,"class")<-"scope.logistic"  
  scopemod$cverrors = NULL
  scopemod$lambdaseq = NULL
  scopemod$beta.full = NULL
  scopemod$beta.best = NULL
  scopemod$fold.assign = NULL
  

  n = length(y)
  p = dim(x)[ 2 ]
  factor_ind = rep(F, p)
  for ( j in 1:p ) {
    if (( class(x[ , j ]) != "numeric" ) && ( class(x[ , j ]) != "numeric" )) factor_ind[ j ] = T
  }
  xshrink = data.frame(x[ , factor_ind, drop = F ])
  if ( include_intercept == FALSE ) {
    xlinear = as.matrix(x[ , !factor_ind, drop = F ])
  } else {
    xlinear = as.matrix(cbind(1, x[ , !factor_ind, drop = F ]))
  }
  plinear = dim(xlinear)[ 2 ]
  pshrink = dim(xshrink)[ 2 ]
  for ( j in 1:pshrink ) xshrink[ , j ] = as.factor(xshrink[ , j ])
  include_intercept = FALSE
  
  P = solve(t(xlinear) %*% xlinear) %*% t(xlinear)
  catnumbers = rep(0, pshrink)
  mcpContribution = rep(0, pshrink)
  catnames = list()
  # Store names (and number of) levels in the categorical variables
  for ( j in 1:pshrink ) {
    catnames[[ j  ]] = levels(xshrink[ , j ])
    catnumbers[ j ] = length(catnames[[ j ]])
  }

  if ( is.null(lambda) ) {
    pathlength = nlambda
  } else {
    if ( is.null(dim(lambda)) ) {
      lambda = t(as.matrix(lambda)) 
    }
    pathlength = dim(lambda)[ 2 ]
  }

  coefficientshrink = list()
  # Sample (and then fix) uniformly random permutation of variables for order of block descent
  if ( is.null(block_order) ) block_order = sample(1:pshrink)
  for ( j in 1:pshrink ) {
    coefficientshrink[[ j ]] = matrix(0, catnumbers[ j ], pathlength)
    rownames(coefficientshrink[[ j ]]) = catnames[[ j ]]
  }
  coefficientlinear = matrix(0, plinear, pathlength)
  beta = rep(0, plinear)
  subaverages = list()
  weights = list()
  weightsbool = list()
  for ( j in 1:pshrink ) {
    # initialize subaverages object, compute the weights (recall they're fixed a priori so this needs doing once)
    weights[[ j ]] = rep(0, catnumbers[ j ])
    weightsbool[[ j ]] = rep(FALSE, catnumbers[ j ])
    subaverages[[ j ]] = rep(0, catnumbers[ j ])
    for ( k in 1:catnumbers[ j ] ) {
      weights[[ j ]][ k ] = sum(xshrink[ , j ] == catnames[[ j ]][ k ]) / n
    }
    # weightsbool stores when a level has no observations, so that we never end up dividing by zero
    weightsbool[[ j ]] = (weights[[ j ]] > 0)
  }
  partialresiduals = y

  # Now a short routine to decide on the scaling for default tuning parameters
  beta = P %*% partialresiduals
  partialresiduals = partialresiduals - xlinear %*% beta
  minstdev = Inf
  for ( j in 1:pshrink ) {
    subaverages[[ j ]] = tapply(partialresiduals, xshrink[ , j ], mean)[ catnames[[ j ]] ]
    minstdev = min(minstdev, sqrt(var(subaverages[[ j ]][ weightsbool[[ j ]] ] * sqrt(n * weights[[ j ]][ weightsbool[[ j  ]] ]))))
  }

  if ( is.null(noise_variance) ) {
    noise_variance = 0.0125 * minstdev # We want this to be an underestimate; if we don't fit null model at pathpoint 1, we start again with 2x value
  }


  # Generates the matrix of lambda values in the case that we use default arguments - initialise the lambda values here in a data-driven way
  if ( is.null(lambda) ) {
    baseseq = as.matrix(exp(seq(log( 8 * noise_variance / sqrt(n)), log(lambda_min_ratio * 8 * noise_variance / sqrt(n)), length = nlambda)))
    lambda = t(baseseq %*% (catnumbers^(0.5))) # rescales the sequence of lambda by this, such that if all variables have no signal (and have
    # equal size categories) then they'll have consistent scaling for recovery of true (intercept-only) solution
  } else { 
    
    if (sum(lambda <= 0) > 0) {
      stop('All lambda values must be strictly positive')
    } else if (dim(lambda)[ 1 ] != pshrink) {
      stop('lambda must be pshrink times pathlength matrix with each row a positive decreasing sequence')
    } else for (j in 1:pshrink) {
      if (sum(diff(lambda[ j, ]) > 0) > 0) {
        stop('lambda sequence for each categorical variable must be decreasing')
      }
    }
  }
  
  # (Leftover from testing the LQA routine -- testing zero-penalty against simple examples in glm)
  if ( zero_penalty == TRUE ) {
    lambda = lambda[ , 1:2 ]
    lambda[ , 2 ] = rep(0, pshrink)
  }
  # Split up the observations into different folds
  if ( nfolds > 1 ) {
    if ( is.null(fold_assignment) ) {
      fold_assignment = as.integer(sample(ceiling((1:n)*nfolds/n)))
      scopemod$fold.assign = fold_assignment #16SEP
    }
    cverrors = matrix(0, n, dim(lambda)[ 2 ])
    removecounter = 0
    counter = 0

    for ( k in 1:nfolds ) {
      if ( silent == FALSE ) print(paste0("Fold ", k))
      yfold = y[ (fold_assignment != k), drop = FALSE ]
      xlinearfold = xlinear[ (fold_assignment != k), , drop = FALSE ]
      xshrinkfold = xshrink[ (fold_assignment != k), , drop = FALSE ]
      yremove = y[ (fold_assignment == k), drop = FALSE ]
      xlinearremove = xlinear[ (fold_assignment == k), , drop = FALSE ]
      xshrinkremove = xshrink[ (fold_assignment == k), , drop = FALSE ]
      nremove = length(yremove)
      keepidentifier = rep(TRUE, nremove)
      # If a category is not present in the training data, remove all observations including it from the test data
      for ( i in 1:nremove ) {

        for ( j in 1:pshrink ) {

          if ( xshrinkremove[ i, j ] %in% xshrinkfold[ , j ] == FALSE ) {
            keepidentifier[ i ] = FALSE
            removecounter = removecounter + 1

          }
        }
      }
      yremove = yremove[ keepidentifier, drop = FALSE ]
      xlinearremove = xlinearremove[ keepidentifier, , drop = FALSE ]
      xshrinkremove = xshrinkremove[ keepidentifier, , drop = FALSE ]

      # Compute a single solution path for this fold
      cvsolution = core_scope.logistic(yfold, xlinearfold, xshrinkfold, block_order, k, gamma, (early_stopping_criterion == "AIC"), early_stopping_criterion, lambda, terminate_eps,
                                           !include_intercept, max_iter, max_out_iter, early_stopping, early_stopping_rounds,
                                           silent, grid_safe)
      # Retain the scaling of the tuning parameter from the first fold
      if ( k == 1 ) {
        # Keep scaling of tuning parameter from the first fold
        lambda = cvsolution[[ 4 ]]
        if ( is.null(dim(lambda)) ) {
          lambda = t(as.matrix(lambda)) 
        }
      }
      
      cvtemp = xlinearremove %*% cvsolution[[ 1 ]]
      for ( j in 1:pshrink ) {
        cvtemp = cvtemp + cvsolution[[ 2 ]][[ j ]][ xshrinkremove[ , j], ]
      }
      cverrorstemp = abs(yremove - inv.logit(cvtemp))


      cverrors[ (counter + 1):(counter + length(yremove)), 1:dim(cverrorstemp)[ 2 ] ] = as.numeric(cverrorstemp)

      counter = counter + length(yremove)
    }

    cverrors = as.matrix(cverrors[ 1:(n - removecounter), 1:dim(cverrorstemp)[ 2 ] ])
    if ( removecounter > 0 ) {
      warning(paste0(removecounter, " observations removed from test sets; number of evaluated predictions is ", n - removecounter, "."))
    }
    # Computes cross-validation errors and selects optimal lambda
    cverrors = colMeans(cverrors > 0.5)
    cverrors[ is.na(cverrors) ] = Inf # If we get NA as result of fitting saturated model
    scopemod$cverrors = cverrors
    if ( only_cross_validate == TRUE ) {
      # If we only want to return the results of the cross-validation. Used if, for example, one wants to also cross-validate over gamma
      
      return(scopemod)
      # break
    }
    pathlengthfinal = which.min(cverrors)
    lambdaseqused = lambda
    lambda = lambda[ , 1:pathlengthfinal, drop = FALSE ] 
    
    if ( silent == FALSE ) print(paste0("Minimal cross-validation error = ", min(cverrors), " at pathpoint ", pathlengthfinal))
    
    scopemod$lambda = lambdaseqused
    
    # Compute final solution with cross-validated tuning parameter
    fullsolution = core_scope.logistic(y, xlinear, xshrink, block_order, 2, gamma, (early_stopping_criterion == "AIC"), early_stopping_criterion, lambda, terminate_eps,
                                       !include_intercept, max_iter, max_out_iter, early_stopping, early_stopping_rounds,
                                       silent, grid_safe )

    if ( return_full_beta == TRUE ) {
      scopemod$beta.full = list()
      scopemod$beta.full[[ 1 ]] = fullsolution[[ 1 ]]
      scopemod$beta.full[[ 2 ]] = fullsolution[[ 2 ]]
    }
    
    
    
    # This is if we only want to print out the solution at CV-optimal lambda (default TRUE)
    fullsolution[[ 1 ]] = matrix(fullsolution[[ 1 ]], plinear, pathlengthfinal)[ , pathlengthfinal ]
    for ( j in 1:pshrink ) {
      
      fullsolution[[ 2 ]][[ j ]] = as.matrix(fullsolution[[ 2 ]][[ j ]])[ , pathlengthfinal ]
      
      
    }
    fullsolution = list(fullsolution[[ 1 ]], fullsolution[[ 2 ]])
    scopemod$beta.best = list()
    scopemod$beta.best[[ 1 ]] = fullsolution[[ 1 ]]
    scopemod$beta.best[[ 2 ]] = fullsolution[[ 2 ]]
    
    
    
    return(scopemod)
    
    
  } else {

    solution = core_scope.logistic(y, xlinear, xshrink, block_order, 1, gamma, (early_stopping_criterion == "AIC"), early_stopping_criterion, lambda, terminate_eps,
                                   !include_intercept, max_iter, max_out_iter, early_stopping, early_stopping_rounds,
                                   silent, grid_safe )

    pathlengthfinal = dim(solution[[ 2 ]][[ 1 ]])[ 2 ]

    
    if ( plinear > 1 ) {
      solution[[ 1 ]] = solution[[ 1 ]][ , 1:pathlengthfinal ]
    } else {
      solution[[ 1 ]] = solution[[ 1 ]][ 1:pathlengthfinal ]
    }
    
    for ( j in 1:pshrink ) {
      if ( pathlengthfinal > 1 ) {
        solution[[ 2 ]][[ j ]] = solution[[ 2 ]][[ j ]][ , 1:pathlengthfinal ]
      }
      
    }
    
    
    fullsolution = list()
    fullsolution$beta.full[[ 1 ]] = solution[[ 1 ]]
    fullsolution$beta.full[[ 2 ]] = solution[[ 2 ]]
    scopemod$beta.full = fullsolution$beta.full 
    lambda = lambda[ , 1:pathlengthfinal ]
    scopemod$lambda = lambda
    
    
    return(scopemod)
  }

}

