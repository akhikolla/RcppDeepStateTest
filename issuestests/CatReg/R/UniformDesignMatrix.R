# SCRIPT TO GENERATE NEW RANDOM MATRICES WITH UP TO 26 CATEGORIES IN EACH VARIABLE


longletters<-function()
{
    LONGLETTERS = rep("0",27*26)
    LONGLETTERS[1:26] = LETTERS
    for (i in 1:26) {
        for (j in 1:26) {
            LONGLETTERS[26*i + j] = paste0(LETTERS[i],LETTERS[j])
        }
    }
    return(LONGLETTERS)
}



#' Create a design matrix of categorical variables.
#'
#' @name UniformDesignMatrix
#'
#' @description Function for use in simulations, creating design matrix of categorical variables where each column is uniformly randomly distributed and independent.
#'
#' @param n Number of observations
#' @param p Number of variables
#' @param c Number of categories within each variable
#' 
#' @return A data frame of categorical (factor) variables.
#' 
#' @examples
#' x = UniformDesignMatrix(100, 10, 8)
#' @export
UniformDesignMatrix = function( n, p, c ) {
  emptymatrix = matrix(0, n, p)
  cholmat = chol(diag(p))
  for ( i in 1:n ) {
    emptymatrix[ i, ] = fastrmvnorm(cholmat, cholesky = T)
  }

  emptymatrix = pnorm(emptymatrix)

  emptymatrix = ceiling(c * emptymatrix)
  finalmatrix = matrix(0, n, p)
  for ( i in 1:n ) {
    for ( j in 1:p ) {
      finalmatrix[ i, j ] = paste0(longletters()[ emptymatrix[ i, j ] ], j)
    }
  }
  finalmatrix = as.data.frame(finalmatrix, stringsAsFactors = TRUE)
  return(finalmatrix)
}


#' Create a design matrix of categorical variables with correlated columns.
#'
#' @name CorrelatedDesignMatrix 
#'
#' @description Function for use in simulations. Created design matrix of categorical variables with correlated columns
#'
#' @param n Number of observations
#' @param cov_mat p x p covariance matrix. Controls correlations of pairs of marginally U[0,1] random variables that are subsequently binned to assign categories for each variable
#' @param c Number of categories within each variable
#'
#' @return  A data frame of categorical (factor) variables.

#' @examples
#' # Generate matrix of marginal U[0,1] variables, 0.5 pairwise correlation, that are
#' # discretised into factor variables
#' cov_mat = 0.5 * diag(10) + 0.5 * matrix(1, 10, 10)
#' x = CorrelatedDesignMatrix(100, cov_mat, 8)
#' 
#' @export
CorrelatedDesignMatrix = function( n, cov_mat, c ) {
  if (( dim(cov_mat)[ 1 ] != dim(cov_mat)[ 2 ] )){
    stop("Incorrect input arguments")
  }
  cov_mat = 2 * sin( cov_mat * pi / 6 ) # ensures that once transformed back to uniform, correlation between uniforms is correct
  cholmat = chol(cov_mat)
  p = dim(cov_mat)[ 1 ]
  emptymatrix = matrix(0, n, p)
  for ( i in 1:n ) {
    emptymatrix[ i, ] = fastrmvnorm(cholmat, cholesky = T)
  }

  emptymatrix = pnorm(emptymatrix)

  emptymatrix = ceiling(c * emptymatrix)
  finalmatrix = matrix(0, n, p)
  for ( i in 1:n ) {
    for ( j in 1:p ) {
      finalmatrix[ i, j ] = paste0(longletters()[ emptymatrix[ i, j ] ], j)
    }
  }
  finalmatrix = as.data.frame(finalmatrix, stringsAsFactors = TRUE)
  return(finalmatrix)
}
