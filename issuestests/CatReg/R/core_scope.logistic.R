
core_scope.logistic = function ( y, xlinear, xshrink, blockorder, fold, gamma, AIC, mBICconstant,  lambdaseq, TerminateEpsilon,
                                 interceptxlinear, max.iter, max.out.iter, BICearlystop, BICterminate, silent, grid.safe ) {

  inv.logit = function ( x ) {
    if ( abs(x) > 20 ) {
      return(0.5 * (sign(x) + 1))
    } else {
      return(exp(x) / ( 1 + exp(x) ))
    }
  }
  inv.logit = Vectorize(inv.logit)

  logit = function( x ) return(log( x / ( 1 - x )))

  # Next two variables are used for step-size halving
  alpha = 1
  step.halve = 25

  n = length(y)
  null.deviance = - sum(y) * log(mean(y)) - sum(1 - y) * log( 1 - mean(y))
  deviance = null.deviance
  TerminateCriterion = null.deviance * TerminateEpsilon #rewrite this thing, this is not the correct null deviance!!!
  ObjectiveValue = null.deviance
  OldObjectiveValue = 0

  lambdaseq.augment = FALSE

  plinear = dim(xlinear)[ 2 ]
  pshrink = dim(xshrink)[ 2 ]
  beginagain = FALSE

  # Wrapper should make this always set to TRUE
  if ( interceptxlinear == FALSE ) {
    xlinear = cbind(1, xlinear)
    plinear = plinear + 1
  }
  P = solve(t(xlinear) %*% xlinear) %*% t(xlinear)
  catnumbers = rep(0, pshrink)
  mcpContribution = rep(0, pshrink)
  catnames = list()
  for ( j in 1:pshrink ) {
    catnames[[ j  ]] = levels(xshrink[ , j ])
    catnumbers[ j ] = length(catnames[[ j ]])
  }

  if ( is.null(dim(lambdaseq)) ) {
    lambdaseq = t(as.matrix(lambdaseq)) # Sept2020
  }

  pathlength = dim(lambdaseq)[ 2 ]
  # If not fold 1, augments the solution path to be safe that we start from the initial solution being zero for all categorical variables
  if (( fold > 1 ) && ( pshrink > 1 ) && ( dim(lambdaseq)[ 2 ] > 1 ) && ( grid.safe > 0 )) {
    lambdaseq = cbind(matrix(0, pshrink, grid.safe), lambdaseq)
    lambdaratio = lambdaseq[ 1, grid.safe + 1 ] / lambdaseq[ 1, grid.safe + 2 ]
    for ( i in seq(grid.safe, 1, -1) ) {
      lambdaseq[ , i ] = lambdaratio * lambdaseq[ , i + 1 ]
    }
    lambdaseq.augment = TRUE
    pathlength = pathlength + grid.safe
  }

  if ( BICearlystop == FALSE ) {
    BICterminate = pathlength
  }
  coefficientshrink = list()
  oldcoefficientshrink = list()

  for ( j in 1:pshrink ) {
    coefficientshrink[[ j ]] = matrix(0, catnumbers[ j ], pathlength)
    oldcoefficientshrink[[ j ]] = rep(0, catnumbers[ j ])
    rownames(coefficientshrink[[ j ]]) = catnames[[ j ]]

  }
  coefficientlinear = matrix(0, plinear, pathlength)
  beta = rep(0, plinear)
  oldbeta = rep(0, plinear)

  subaverages = list()
  weights = list()
  weightsbool = list()
  for ( j in 1:pshrink ) {
    # Compute initial weights -- unlike Gaussian version these will have to be recomputed at each LQA iteration
    weights[[ j ]] = rep(0, catnumbers[ j ])
    weightsbool[[ j ]] = rep(FALSE, catnumbers[ j ])
    subaverages[[ j ]] = rep(0, catnumbers[ j ])
    for ( k in 1:catnumbers[ j ] ) {
      weights[[ j ]][ k ] = sum(xshrink[ , j ] == catnames[[ j ]][ k ]) / n
    }
    weightsbool[[ j ]] = (weights[[ j ]] > 0)
  }
  partialresiduals = y
  BIC = rep(0, pathlength)
  fittedvalues = rep(0, n)
  adaptivefittedvalues = fittedvalues
  fittedprobs = rep(0.5, n)
  partialresiduals = ( y - fittedprobs ) / ( fittedprobs * ( 1 - fittedprobs ) )
  oldpartialresiduals = rep(0, n)
  beta = rep(0, plinear)
  OuterOldObjectiveValue = 0
  OuterObjectiveValue = 0
  BICincreasecounter = 0
  effd = 1 # dimension of the model
  model.saturated = FALSE
  for ( l in 1:pathlength ) {

    if ( BICincreasecounter > BICterminate ) {
      l = l - 1
      break
    } else if ( ( fold > 1 ) && ( model.saturated ) ) {
      # Routine to deal with saturated model. Once satisfied saturation checks then model is kept fixed
      if ( l < pathlength ) {
        coefficientlinear[ , l + 1 ] = coefficientlinear[ , l ]
        for ( j in 1:pshrink ) {
          coefficientshrink[[ j ]][ , l + 1 ] = coefficientshrink[[ j ]][ , l ]
        }
        out.iter = max.out.iter
      }

    } else {

      out.iter = 0

      # MIDDLE LOOP
      while ((( out.iter < max.out.iter ) && ( abs(OuterOldObjectiveValue - OuterObjectiveValue) > TerminateCriterion )) || ( out.iter == 0 )) {
        iter = 0

        oldpartialresiduals = partialresiduals
        observationweights = as.vector(fittedprobs * ( 1 - fittedprobs )) / n

        # Code for dealing with fitted probabilities close to 0 or 1 -- copies glmnet approach
        repvec = (pmin(fittedprobs, 1 - fittedprobs) < 1e-5) # identifies observations with fitted probs close to 0 or 1


        fittedprobs[ repvec ] = round(fittedprobs[ repvec ])
        observationweights[ repvec ] = 1e-5
        totalweights = sum(observationweights)
        observationweights = observationweights / totalweights
        gammascale = gamma * totalweights

        partialresiduals = as.vector(( y - fittedprobs ) / ( fittedprobs * ( 1 - fittedprobs ) ))
        partialresiduals[ repvec ] = oldpartialresiduals[ repvec ]
        middleresponse = partialresiduals + adaptivefittedvalues
        P = solve( t(xlinear) %*% ( observationweights * xlinear )) %*% t( observationweights * xlinear )

        OuterOldObjectiveValue = OuterObjectiveValue

        for ( j in 1:pshrink ) {
          weights[[ j ]] = tapply(observationweights, xshrink[ , j ], sum, default = 0)[ catnames[[ j ]] ]
          coefficientshrink[[ j ]][ weightsbool[[ j ]], l ] = coefficientshrink[[ j ]][ weightsbool[[ j ]], l ] - sum(weights[[ j ]][ weightsbool[[ j ]] ] * coefficientshrink[[ j ]][ weightsbool[[ j ]], l ])
        }
        ObjectiveValue = Inf

        oldbeta = beta

        for ( j in 1:pshrink ) {
          oldcoefficientshrink[[ j ]] = coefficientshrink[[ j ]][ , l ]
        }

        inner.null.deviance = sum((middleresponse - mean(middleresponse))^2) / (2 * n)
        InnerTerminateEpsilon = TerminateEpsilon * inner.null.deviance
        # INNER LOOP
        while (( iter < max.iter ) && (( abs(OldObjectiveValue - ObjectiveValue) > InnerTerminateEpsilon ) || ( beginagain ) || ( iter == 0 ) )) {
          if ( beginagain == TRUE ) {
            iter = 0
            beginagain = FALSE
          }
          OldObjectiveValue = ObjectiveValue
          oldpartialresiduals = partialresiduals
          partialresiduals = partialresiduals + as.vector(xlinear %*% beta)
          beta = as.vector(P %*% as.matrix(partialresiduals))
          partialresiduals = partialresiduals - as.vector(xlinear %*% beta)

          fittedvalues = rep(0, n)
          effdold = effd
          fittedvalues = fittedvalues + as.vector(xlinear %*% beta)

          partialresiduals = partialresiduals - sum(observationweights * partialresiduals)
          effd = length(beta)
          for ( j in 1:pshrink ) {

            lambda = lambdaseq[ blockorder[ j ], l ] / totalweights
            partialresiduals = partialresiduals + as.vector(coefficientshrink[[ blockorder[ j ] ]][ xshrink[ ,blockorder[ j ] ] , l ])
            subaverages[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]] ] = tapply(observationweights * partialresiduals, xshrink[ , blockorder[ j ] ], sum, default = 0)[ catnames[[ blockorder[ j ] ]] ][ weightsbool[[ blockorder[ j ] ]] ] / weights[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]] ]

            coefficientshrink[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]], l ] = DoBlock(weights[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]] ], subaverages[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]]], gammascale, lambda)

            if ( mean(abs(coefficientshrink[[ blockorder[ j ] ]][ , l ])) < 1e-8 ) {
              coefficientshrink[[ blockorder[ j ] ]][ , l ] = rep(0, catnumbers[ blockorder[ j ] ])
            }
            effd = effd + length(unique(coefficientshrink[[ blockorder[ j ] ]][ , l ])) - 1

            # Compute penalty contributino to objective for variable blockorder[ j ]
            mcpContribution[ blockorder[ j ] ] = sum(mcpDifferences(coefficientshrink[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]], l ], gammascale, lambda))

            if ( ( fold == 1 ) && ( l == 1 ) && ( length(unique(coefficientshrink[[ blockorder[ j ] ]][ , 1 ])) > 1 ) ) {
              # If we fit a non-zero solution at the first solution value, restart process with larger penalty value
              if ( silent == FALSE) {
                if ( silent == FALSE ) print("Started from too small a penalty value. Doubling parameter path and starting again.")
              }

              coefficientshrink[[ blockorder[ j ] ]][ , 1 ] = rep(0, catnumbers[ blockorder[ j ] ])
              lambdaseq = 2 * lambdaseq
              beginagain = TRUE
              # break
            }
            partialresiduals = partialresiduals - as.vector(coefficientshrink[[ blockorder[ j ] ]][ xshrink[ ,blockorder[ j ] ] , l ])
            fittedvalues = fittedvalues + as.vector(coefficientshrink[[ blockorder[ j ] ]][ xshrink[ , blockorder[ j ] ], l ])

          }
          ObjectiveValue = totalweights * ((0.5 * sum(observationweights * partialresiduals^2)) + sum(mcpContribution))

          iter = iter + 1
          if (( iter %% 100 == 0 ) && ( silent == FALSE )) {
            if ( silent == FALSE ) print(paste0("Pathpoint ", l - ( fold != 1) * grid.safe, " ongoing; iteration = ", iter , "."))
          }


        }
        # END OF INNER LOOP
        # Step size for LQA iteration
        beta = alpha * beta + ( 1 - alpha ) * oldbeta
        for ( j in 1:pshrink ) {
          coefficientshrink[[ j ]][ , l ] = alpha * coefficientshrink[[ j ]][ , l ] + ( 1 - alpha ) * oldcoefficientshrink[[ j ]]
        }
        adaptivefittedvalues = rep(0, n)
        adaptivefittedvalues = adaptivefittedvalues + as.vector(xlinear %*% beta)
        adaptivemcpContribution = rep(0, pshrink)
        for ( j in 1:pshrink ) {
          adaptivefittedvalues = adaptivefittedvalues + as.vector(coefficientshrink[[ j ]][ xshrink[ , j ], l ])
          adaptivemcpContribution[ j ] = sum(mcpDifferences(coefficientshrink[[ j ]][ weightsbool[[ j ]], l ], gammascale, lambdaseq[ j, l ] / totalweights))
        }


        fittedprobs = as.vector(inv.logit(adaptivefittedvalues))


        out.iter = out.iter + 1
        if ( out.iter %% 100 == 0 ) {
          if ( silent == FALSE ) print(paste0("Outer iteration ", out.iter, "."))
        }

        if ( out.iter == step.halve ) {
          step.halve = step.halve + min(round(12.5 / alpha), 50)
          alpha = 0.5 * alpha
        }

        OuterObjectiveValue = ( sum(log(1 + exp(- ( 2 * y - 1 ) * adaptivefittedvalues))) / n ) + totalweights * sum(adaptivemcpContribution)

        deviance = - sum(log(1 - y + fittedprobs * (2 * y - 1)))

        # Next forces program to terminate early in case of saturation. Criteria are: more than half of fitted probabilities being zero or one, or
        # deviance being less than 1% of null deviance
        if ( ( sum(pmin(fittedprobs, 1 - fittedprobs) < 1e-5) >= 0.5 * n ) || ( deviance / null.deviance - 0.01 < 0 ) ) {
          if ( silent == FALSE ) print("Model saturated")
          if ( fold == 1 ) {
            BICincreasecounter = BICterminate + 1
            out.iter = max.out.iter
          } else {
            model.saturated = TRUE
            out.iter = max.out.iter
          }
        }

        # END OF MIDDLE LOOP
      }

      coefficientlinear[ , l ] = beta
      alpha = 1
      step.halve = 25

      # Computes value of information criterion at solution
      if ( AIC == TRUE ) {
        BIC[ l ] =  2 * ( plinear + 1 - as.numeric(interceptxlinear) )
      } else {
        BIC[ l ] =  mBICconstant * log(n + plinear + pshrink) * ( plinear + 1 - as.numeric(interceptxlinear) )
      }

      fitvals = xlinear %*% coefficientlinear[ , l ]

      for ( j in 1:pshrink ) {
        if ( AIC == TRUE ) {
          BIC[ l ] = BIC[ l ] +  2 * ( length(unique(coefficientshrink[[ j ]][ weightsbool[[ j ]], l ])) - 1 )
        } else {
          BIC[ l ] = BIC[ l ] +  mBICconstant * log(n + plinear + pshrink) * ( length(unique(coefficientshrink[[ j ]][ weightsbool[[ j ]], l ])) - 1 )
        }

        fitvals = fitvals + coefficientshrink[[ j ]][ xshrink[ , j ], l ]
      }
      if ( AIC == TRUE ) {
        BIC[ l ] = BIC[ l ] + 2 * ( sum(log(1 + exp(- ( 2 * y - 1 ) * fitvals))) )
      } else {
        BIC[ l ] = BIC[ l ] + (1 / n) * ( t(y - fitvals) %*% (y - fitvals) )
        BIC[ l ] = BIC[ l ] + ( sum(log(1 + exp(- ( 2 * y - 1 ) * fitvals))) )
      }

      if ( ( fold == 1 ) && ( BICincreasecounter <= BICterminate ) ) {
        if ( l >= 2 ) {
          if ( BICearlystop == TRUE ) {
            BICincreasecounter = l - which.min(BIC[ 1:l ])
          }

        }
      }

      # If coefficients are essentially zero this sets them to exactly zero
      for ( j in 1:pshrink ) {
        if ( mean(abs(coefficientshrink[[ j ]][ , l ])) < 1e-12 ) {
          coefficientshrink[[ j ]][ , l ] = rep(0, catnumbers[ j ])
        }
      }



      if ( l < pathlength ) {
        for ( j in 1:pshrink ) {
          coefficientshrink[[ j ]][ , l + 1 ] = coefficientshrink[[ j ]][ , l ]
        }
      }

      if ( fold == 1 ) {
        if ( silent == FALSE ) print(paste0("Pathpoint ", l - ( fold != 1) * grid.safe, " done; iteration = ", iter, ", outer iteration ", out.iter, ", AIC = ", BIC[ l ], ", stopping counter = ", BICincreasecounter, ", model dimension = ", effd, "."))
      } else {
        if ( silent == FALSE ) print(paste0("Pathpoint ", l - ( fold != 1) * grid.safe, " done; iteration = ", iter, ", outer iteration ", out.iter, ", AIC = ", BIC[ l ], ", model dimension = ", effd, "."))
      }



    }
    pathpoint.finished = l
  }

  pathlength = pathpoint.finished
  if ( lambdaseq.augment == TRUE ) {
    coefficientlinear = coefficientlinear[ , -(1:grid.safe), drop = FALSE ]
    for ( j in 1:pshrink ) {
      coefficientshrink[[ j ]] = coefficientshrink[[ j ]][ , -(1:grid.safe) ]
    }
    BIC = BIC[ -(1:grid.safe) ]
    pathlength = pathlength - grid.safe
  }
  coefficientlinear = coefficientlinear[ , 1:pathlength ]
  BIC = BIC[ 1:pathlength ]
  for ( j in 1:pshrink ) {
    coefficientshrink[[ j ]] = coefficientshrink[[ j ]][ , 1:pathlength ]
  }
  lambdaseq = lambdaseq[ , 1:pathlength ]

  if ( AIC == TRUE ) {
    if ( silent == FALSE ) print(paste0("Smallest AIC model is pathpoint = ", which.min(BIC), ", AIC = ", min(BIC), ", terminated at pathpoint ", pathlength, "."))
  } else {
    if ( silent == FALSE ) print(paste0("Smallest BIC model is pathpoint = ", which.min(BIC), ", BIC = ", min(BIC), ", terminated at pathpoint ", pathlength, "."))
  }
  return(list(coefficientlinear, coefficientshrink, BIC, lambdaseq))
}

