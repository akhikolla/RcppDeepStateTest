fastrmvnorm = function( cov_mat, cholesky = FALSE ) {
  if ( cholesky == FALSE ) {
    cov_mat = chol(cov_mat)
  }
  d = dim(cov_mat)[ 1 ]
  return(as.vector(t(cov_mat) %*% rnorm(d)))
}

