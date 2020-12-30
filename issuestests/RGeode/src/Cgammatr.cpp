#include <Rcpp.h>
#include"genhu.h"

using namespace Rcpp;


// [[Rcpp::export]]

NumericVector Cgammatr(int n, double A, double B,
                       NumericVector range){

  NumericVector u(n);

  double a1= range[0];
  double a2= range[1];
  double smallvalue = 1e-8;

  double cdf1 = R::pgamma(a1, A, 1/B, 1, 0);
  double cdf2 = R::pgamma(a2, A, 1/B, 1, 0);

  if(  ((cdf1>1-smallvalue) && (cdf2>1-smallvalue)) ||
       ((cdf1<smallvalue) && (cdf2 < smallvalue))  )
  {
    for(int i = 0; i < n; ++i)
    {
      u[i]= a1*((cdf1>1-smallvalue) && (cdf2>1-smallvalue)) +
        a2*((cdf1<smallvalue) && (cdf2 < smallvalue));
    }
  }

  else
  {
    for(int i = 0; i < n; ++i)
    {
      u[i]= R::qgamma(cdf1+ R::runif(0,1)*(cdf2- cdf1), A, 1/B, 1, 0);
    }
  }



  return u;
}
