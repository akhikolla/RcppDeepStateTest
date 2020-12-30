#include <Rcpp.h>
#include"genhtau.h"

using namespace Rcpp;


// [[Rcpp::export]]

NumericVector Cexptr(int n, double lambda, NumericVector range){

  NumericVector u(n);

  double a1= range[0];
  double a2= range[1];
  double smallvalue = 1e-8;

  double cdf1 = R::pexp(a1, 1/lambda, 1, 0);
  double cdf2 = R::pexp(a2, 1/lambda, 1, 0);

  if(cdf2-cdf1< smallvalue)
  {
    for(int i = 0; i < n; ++i)
    {
      u[i]= a1;
    }
  }


  else
  {
    for(int i = 0; i < n; ++i)
    {
      u[i]= R::qexp(cdf1+ R::runif(0,1)*(cdf2- cdf1), 1/lambda, 1, 0);
    }
  }


  return u;
}
