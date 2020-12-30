
#' Computes SCOPE logistic predictions 
#'
#' @description Computes SCOPE logistic predictions on new data 
#'
#' @param object SCOPE model as outputted by scope.logistic. Must have simply.the.best = TRUE
#' @param newdata New covariates on which to make predictions. Must be of the same form as the model was trained on
#' @param probs	If TRUE returns probabilities, if FALSE returns binary predictions
#' @param include_intercept If TRUE, a column of 1s will be added to the (continuous) design matrix. Must match format of training data.
#' @param ... Additional arguments to pass to other \code{predict} methods
#' 
#' @return Returns n-length vector of predictions
#'
#' @seealso \code{\link{scope.logistic}}
#'
#' @export
predict.scope.logistic = function(object, newdata, probs = TRUE, include_intercept = TRUE,...)
{
  model<-object  
  inv.logit = function( x ) return(exp(x)/(1 + exp(x)))
  model = model$beta.best
  p = dim(newdata)[ 2 ]
  factor_ind = rep(F, p)
  for ( j in 1:p ) {
    if (( class(newdata[ , j ]) != "numeric" ) && ( class(newdata[ , j ]) != "numeric" )) factor_ind[ j ] = T
  }
  xshrink = data.frame(newdata[ , factor_ind, drop = F ])
  if ( include_intercept == FALSE ) {
    xlinear = as.matrix(newdata[ , !factor_ind, drop = F ])
  } else {
    xlinear = as.matrix(cbind(1, newdata[ , !factor_ind, drop = F ]))
  }
  for ( j in 1:dim(xshrink)[ 2 ] ) xshrink[ , j ] = as.factor(xshrink[ , j ])
  predvec = xlinear %*% model[[ 1 ]]
  for ( j in 1:dim(xshrink)[ 2 ] ) {
    predvec = predvec + model[[ 2 ]][[ j ]][ xshrink[ , j ] ]
  }
  predvec = inv.logit(predvec)
  if ( probs == F ) predvec = round(predvec)
  
  return(predvec)
}
