#' @title Brute-force calculation of an expected permutation matrix
#' @description Computes an expected permutation matrix and marginal likelihood from a matrix of assignment likelihoods. The function literally enumerates all permutations so will be impractial for matrices with more than 10 rows.
#' @param A A matrix of assignment likelihoods.
#' @param return.permanent A logical value indicating whether the function should also return the permanent of \code{A}, which is then added to the output as an attribute.
#' @return \code{E(P)}, the expected permutation matrix corresponding to \code{A}.
#' @examples
#' data(A)
#' brute(A)
brute<-function(A,return.permanent=FALSE){
  n<-nrow(A)
  cnt<-rep(0,n)
  ind<-1:n
  indmat<-cbind(1:n,ind)
  W<-prod(A[indmat])
  EP<-diag(n)
  
  i<-0
  while(i<n){
    
    # The outer parts of this while
    # loop implement Heap's algorithm
    # for enumerating permutations.
    if(cnt[i+1]<i){                                           
    if(i%%2==0){ind[c(1,i+1)]<-ind[c(i+1,1)]                  
    }else{ind[c(i+1,cnt[i+1]+1)]<-ind[c(cnt[i+1]+1,i+1)]}     
    cnt[i+1]<-cnt[i+1]+1
    i<-0
    
    # This part of the code updates
    # the running weighted mean of 
    # permutation matrices.
    indmat<-cbind(1:n,ind)    
    w<-prod(A[indmat])        
    W<-W+w                    
    EP<-EP*(1-w/W)
    EP[indmat]<-EP[indmat]+w/W
    
    }else{
      cnt[i+1]<-0
      i<-i+1
    }
  }
  if(return.permanent){attr(EP,"permanent")<-W}
  EP
}
