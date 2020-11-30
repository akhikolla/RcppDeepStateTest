#' @title Checking a matrix is tridiagonal
#' @description A function for checking whether a matrix is tridiagonal. The check is used before attempting to apply the BG method for computing the permanent, since the method is only applicable to tridiagonal matrices.
#' @param A A matrix.
#' @return A logical variable. \code{TRUE} if the \code{A} is tridiagonal, \code{FALSE} otherwise.
#' @examples
#' data(A)
#' is.tridiagonal(A)
#' data(triA)
#' is.tridiagonal(triA)
is.tridiagonal<-function(A){
  n<-nrow(A)
  R<-A[-n,-1]
  L<-A[-1,-n]
  all(R[upper.tri(R)]==0) & all(L[lower.tri(L)]==0)
}
