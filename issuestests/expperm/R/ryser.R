#' @title The Ryser method for computing an expected permutation matrix
#' @description Computes the expected permutation matrix and marginal likelihood from a matrix of assignment likelihoods using the Ryser method.
#' @param A A matrix of assignment likelihoods.
#' @param return.permanent A logical value indicating whether the function should also return the permanent of \code{A}, which is then added to the output as an attribute.
#' @return \code{E(P)}, the expected permutation matrix corresponding to \code{A}.
#' @examples
#' data(A)
#' ryser(A)
ryser<-function(A,return.permanent=FALSE){
  n<-ncol(A)
  W<-0
  EP<-matrix(0,n,n)
  a<-rep(0,n)
  f<-0:n
  p<-(-1)^n
  while(f[1]<n){
    
    # This part of the algorithm is
    # Knuth's algorithm L for generating
    # a binary Gray code.
    p<--p                             
    j<-f[1]                           
    f[1]<-0              
    f[j+1]<-f[j+2]                    
    f[j+2]<-j+1                       
    a[j+1]<-1-a[j+1]                  
    Ak<-A
    
    # This part of the algorithm is
    # computing the terms of the incl/excl
    # sum in the same way as Ryser's
    # method for computing the permanent.
    Ak[,a==0]<-0                      
    rs<-rowSums(Ak)                   
    w<-p*prod(rs)                     
    if(!(w==0)){                      
    Ak<-sweep(Ak,1,rs,FUN="/")
    W<-W+w
    EP<-EP+w/W*(Ak-EP)
    }
  }
  if(return.permanent){attr(EP,"permanent")<-W}
  EP
}
