#' @title The Brualdi-Gibson method for computing an expected permutation matrix
#' @description Computes the expected permutation matrix and marginal likelihood from a tridiagonal matrix of assignment likelihoods using the Brualdi-Gibson method.
#' @param A A tridiagonal matrix of assignment likelihoods.
#' @param return.permanent A logical value indicating whether the function should also return the permanent of \code{A}, which is then added to the output as an attribute.
#' @return \code{E(P)}, the expected permutation matrix corresponding to \code{A}.
#' @examples
#' data(triA)
#' BG(triA)
BG<-function(A,return.permanent=FALSE){
  if(!is.tridiagonal(A)){
    warning("Input is not tridiagonal.
            This function only works for tridiagonal matrices!")
  }
  n<-nrow(A)
  
  # The algorithm begins by computing two sequences
  # of permanents via the BG contractions.
  Fmat<-A                     
  for(i in 2:n){              
    Fmat[i,i:n]<-Fmat[i-1,i-1]*Fmat[i,i:n]+Fmat[i,i-1]*Fmat[i-1,i:n]
  }
  f<-diag(Fmat)
  Bmat<-A
  for(i in (n-1):1){
    Bmat[i,1:i]<-Bmat[i+1,i+1]*Bmat[i,1:i]+Bmat[i,i+1]*Bmat[i+1,1:i]
  }
  b<-diag(Bmat)

  # The permanents are used to compute the diagonal
  # of EP, the off-diagonals are determined by the
  # sum-to-one constraints.
  EP<-matrix(0,n,n)           
  EP[1,1]<-A[1,1]*b[2]/b[1]   
  EP[n,n]<-A[n,n]*f[n-1]/b[1] 
  if(n>2){for(i in 2:(n-1)){EP[i,i]<-A[i,i]*f[i-1]*b[i+1]/b[1]}}
  for(i in 1:(n-1)){ EP[i,i+1]<-EP[i+1,i]<-1-sum(EP[i,1:i])}

  if(return.permanent){attr(EP,"permanent")<-b[1]}
  EP
}
