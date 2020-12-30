#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix sink_cpp(NumericMatrix A, int maxit=99){
  int n = A.nrow();
  int iter=0;
  NumericVector rsums(n);
  NumericVector csums(n);
  while(iter<maxit){
    iter+=1;
    for(int i=0;i<n;i++){rsums(i)=0;for(int j=0;j<n;j++){rsums(i)+=A(i,j);}}
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){A(i,j)/=rsums(i);}}
    for(int j=0;j<n;j++){csums(j)=0;for(int i=0;i<n;i++){csums(j)+=A(i,j);}}
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){A(i,j)/=csums(j);}}
  }
  return A;
}
