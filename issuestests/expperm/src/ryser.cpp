#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix ryser_cpp(NumericMatrix A) {
  int n = A.nrow();
  NumericVector a(n);
  NumericVector f(n+1);
  for(int i=0;i<(n+1);i++){f(i)=i;}
  int j=0;
  double p=pow(-1,static_cast<double>(n));
  NumericVector rs(n);
  double w=0;
  double W=0;
  NumericMatrix EP(n,n);
  while(f(0)<n){
   p*=-1;                      // The following 6 lines implement Knuth's algorithm L for generating a binary Gray code.
   j=f(0);
   f(0)=0;
   f(j)=f(j+1);
   f(j+1)=j+1;
   a(j)=1-a(j);
   if(a(j)==1){for(int i=0;i<n;i++){rs(i)+=A(i,j);}}     // These 2 lines update the vector of rowsums...
   if(a(j)==0){for(int i=0;i<n;i++){rs(i)-=A(i,j);}}
   w=p;                                                 // ... which are used to compute the weights for the incl/excl sum.
   for(int i=0;i<n;i++){w*=rs(i);}
   if(!(w==0)){
   W+=w;
   for(int i=0;i<n;i++){for(int k=0;k<n;k++){EP(i,k)+=w/W*(a(k)*A(i,k)/rs(i)-EP(i,k));}}     // This line updates the running incl/excl sum.
   }
  }
  return EP;
}
