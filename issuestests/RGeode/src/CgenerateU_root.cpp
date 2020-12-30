#include <Rcpp.h>
#include"genhu.h"

using namespace Rcpp;

// [[Rcpp::export]]

NumericVector CgenerateU_root(NumericVector prodTau, int N, double SIGMAS,
                 NumericMatrix Z){

  int end= prodTau.size();
  double p1;
  double p2;

  NumericVector U(end);

  NumericVector rang(2);
  rang[0]= 0;
  rang[1]= 1;

  for(int i = 0; i < end; ++i)
  {
    p1= prodTau[i]+ N/2;
    p2= 1+ (1/(2*SIGMAS))*sum(Z(_,i)*Z(_,i));

    NumericVector value= Cgammatr(1, p1, p2, rang);

    U[i]= value[0];
  }


  return U;
}
