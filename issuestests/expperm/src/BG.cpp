#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix BG_cpp(NumericMatrix A) {
  int n = A.nrow();
  NumericMatrix F(n,n);
  NumericMatrix B(n,n);
  for(int i=0;i<n;i++){for(int j=0;j<n;j++){F(i,j)=B(i,j)=A(i,j);}}
  NumericMatrix EP(n,n);
  
  for(int i=1;i<n;i++){for(int j=i;j<n;j++){F(i,j)=F(i-1,i-1)*F(i,j)+F(i,i-1)*F(i-1,j);}}
  for(int i=(n-2);-1<i;i--){for(int j=i;-1<j;j--){B(i,j)=B(i+1,i+1)*B(i,j)+B(i,i+1)*B(i+1,j);}}
  
  EP(0,0)=A(0,0)*B(1,1)/B(0,0);
  EP(1,0)=EP(0,1)=1-EP(0,0);
  EP(n-1,n-1)=A(n-1,n-1)*F(n-2,n-2)/F(n-1,n-1);
  EP(n-1,n-2)=EP(n-2,n-1)=1-EP(n-1,n-1);
  for(int i=1;i<(n-1);i++){EP(i,i)=A(i,i)*F(i-1,i-1)*B(i+1,i+1)/B(0,0);}
  for(int i=2;i<(n-1);i++){EP(i,i-1)=EP(i-1,i)=1-EP(i-1,i-1)-EP(i-2,i-1);}
  
  return EP;
}
