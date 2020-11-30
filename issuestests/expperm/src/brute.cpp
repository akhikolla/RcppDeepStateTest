#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix brute_cpp(NumericMatrix A) {
  int n = A.nrow();
  NumericVector ind(n);
  for(int i=0;i<n;i++){ind(i)=i;}
  NumericVector cnt(n);
  double W=0;
  int temp=0;
  NumericMatrix EP(n,n);
  
  double w=1;
  for(int j=0;j<n;j++){w*=A(j,ind(j));}
  W+=w;
  for(int j=0;j<n;j++){EP(j,ind(j))+=w/W;}     // initialize the running mean.
  
  int i=0;                                     // This part of the code is performing Heap's algorithm
  while(i<n){                                  // for visiting the permutations of n objects
    if(cnt(i)<i){
      if((i%2)==0){
        temp=ind(0);ind(0)=ind(i);ind(i)=temp;            // swap 0th and ith elements
      } else {
        temp=ind(cnt(i));ind(cnt(i))=ind(i);ind(i)=temp;  // swap ith and cnt(i)th elements
      }
      cnt(i)+=1;
      i=0;
      
      double w=1;                              // This is the code that updates the running mean      
      for(int j=0;j<n;j++){w*=A(j,ind(j));}    // with the new permutation.
      W+=w;
      for(int j=0;j<n;j++){for(int j2=0;j2<n;j2++){EP(j,j2)*=(1-w/W);}}
      for(int j=0;j<n;j++){EP(j,ind(j))+=w/W;}
      
    } else {
      cnt(i)=0;
      i+=1;
    }
  }
  return EP;
}
