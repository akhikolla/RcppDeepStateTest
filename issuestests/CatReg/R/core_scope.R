core_scope = function ( y, xlinear, xshrink, blockorder, fold, gamma, AIC, mBICconstant,  lambdaseq, TerminateEpsilon,
                        interceptxlinear, max.iter, BICearlystop, BICterminate, silent, grid.safe ) {

  n = length(y)
  null.deviance = t(y - mean(y)) %*% (y - mean(y)) / (2 * n)
  TerminateEpsilon = null.deviance * TerminateEpsilon
  ObjectiveValue = null.deviance
  OldObjectiveValue = 0
  lambdaseq.augment = FALSE

  plinear = dim(xlinear)[ 2 ]
  pshrink = dim(xshrink)[ 2 ]
  beginagain = FALSE

  # Wrapper should have always set this to be TRUE anyway
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
    weightsbool[[ j ]] = (weights[[ j ]] > 0)
  }
  partialresiduals = y
  BIC = rep(0, pathlength)


  BICincreasecounter = 0
  for ( l in 1:pathlength ) {
    if ( BICincreasecounter > BICterminate ) {
      l = l - 1
      break
    } else {


      iter = 0
      oldpartialresiduals = rep(0, n)
      while (( iter < max.iter ) && (( abs(OldObjectiveValue - ObjectiveValue) > TerminateEpsilon ) || ( beginagain ) || ( iter == 0 ) )) {
        # Deal with the linear term and then the variables for which we apply the penalty
        if ( beginagain == TRUE ) {
          iter = 0
          beginagain = FALSE
        }
        # Start of coordinate descent cycle
        OldObjectiveValue = ObjectiveValue
        oldpartialresiduals = partialresiduals
        partialresiduals = partialresiduals + xlinear %*% beta
        beta = P %*% partialresiduals
        partialresiduals = partialresiduals - xlinear %*% beta

        for ( j in 1:pshrink ) {


          partialresiduals = partialresiduals + coefficientshrink[[ blockorder[ j ] ]][ xshrink[ ,blockorder[ j ] ] , l ]
          lambda = lambdaseq[ blockorder[ j ], l ]
          # Computes subaverages for univariate problem
          subaverages[[ blockorder[ j ] ]] = tapply(partialresiduals, xshrink[ , blockorder[ j ] ], mean)[ catnames[[ blockorder[ j ] ]] ]
          # Call C++ code and perform univariate update
          coefficientshrink[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]], l ] = DoBlock(weights[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]] ],
                                                                                                  subaverages[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]]], gamma, lambda)


          # Commented out -- line to force solution to satisfy weighted sum-to-zero constraint (that solution should satisfy anyway)
          # coefficientshrink[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]], l ] = coefficientshrink[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]], l ] - sum(weights[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]] ] * coefficientshrink[[ blockorder[ j ] ]][ weightsbool[[ blockorder[ j ] ]], l ])

          # Computes penalty contribution to objective for variable blockorder[ j ]
          mcpContribution[ blockorder[ j ] ] = sum(mcpDifferences(coefficientshrink[[ blockorder[ j ] ]][ , l ], gamma, lambda))


          if ( ( fold == 1 ) && ( l == 1 ) && ( sqrt(sum(coefficientshrink[[ blockorder[ j ] ]]^2)) > TerminateEpsilon ) ) {
            # If we fit a non-zero solution at the first solution value, restart process with larger penalty value
            if ( silent == FALSE) {
              print("Started from too small a penalty value. Doubling parameter path and starting again.")
            }
            coefficientshrink[[ blockorder[ j ] ]][ , 1 ] = rep(0, catnumbers[ blockorder[ j ] ])
            lambdaseq = 2 * lambdaseq
            beginagain = TRUE
            break
          }


          partialresiduals = partialresiduals - coefficientshrink[[ blockorder[ j ] ]][ xshrink[ ,blockorder[ j ] ] , l ]


        }

        # Computes new value of objective function
        ObjectiveValue = sum(partialresiduals^2) / ( 2 * n ) + sum(mcpContribution)
        iter = iter + 1

        # Prints update of iteration number if still running
        if (( iter %% 100 == 0 ) && ( silent == FALSE )) {
          print(paste0("Pathpoint ", l - ( fold != 1) * grid.safe, " ongoing; iteration = ", iter , "."))
        }


      }

      coefficientlinear[ , l ] = beta

      # After computing solution for pathpoint l, compute value of information criterion at that solution (AIC or modified BIC)
      if ( AIC == TRUE ) {
        BIC[ l ] =  2 * ( plinear + 1 - as.numeric(interceptxlinear) )
      } else {
        BIC[ l ] =  mBICconstant * log(n + plinear + pshrink) * ( plinear + 1 - as.numeric(interceptxlinear) )
      }
      # Compute fitted values
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
        BIC[ l ] = BIC[ l ] + 2 * (1 / n) * ( t(y - fitvals) %*% (y - fitvals) )
      } else {
        BIC[ l ] = BIC[ l ] + (1 / n) * ( t(y - fitvals) %*% (y - fitvals) )
      }

      # Computes number of points between current pathpoint and one with minimum information criterion value. Stops early once this reaches BICterminate
      if ( fold == 1 ) {
        if ( l >= 2 ) {
          if ( BICearlystop == TRUE ) {
            BICincreasecounter = l - which.min(BIC[ 1:l ])
          }

        }
      }



    }

    # Sets up warm start for next parameter value
    if ( l < pathlength ) {
      for ( j in 1:pshrink ) {
        coefficientshrink[[ j ]][ , l + 1 ] = coefficientshrink[[ j ]][ , l ]
      }
    }

    # Prints result from this tuning parameter value
    if ( ( fold == 1 ) && ( silent == FALSE ) ) {
      print(paste0("Pathpoint ", l - ( fold != 1) * grid.safe, " done; iteration = ", iter, ", AIC = ", BIC[ l ], ", stopping counter = ", BICincreasecounter, "."))
    } else if ( silent == FALSE ) {
      print(paste0("Pathpoint ", l - ( fold != 1) * grid.safe, " done; iteration = ", iter, ", AIC = ", BIC[ l ], "."))
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


  if ( ( AIC == TRUE ) && ( silent == FALSE ) ) {
    print(paste0("Smallest AIC model is pathpoint = ", which.min(BIC), ", AIC = ", min(BIC), ", terminated at pathpoint ", pathlength, "."))
  } else {if ( silent == FALSE )
    print(paste0("Smallest BIC model is pathpoint = ", which.min(BIC), ", BIC = ", min(BIC), ", terminated at pathpoint ", pathlength, "."))
  }
  return(list(coefficientlinear, coefficientshrink, BIC, lambdaseq))
}
