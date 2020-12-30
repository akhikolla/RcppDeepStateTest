#include <Rcpp.h>
#include"genhtau.h"

using namespace Rcpp;

// [[Rcpp::export]]

NumericVector CgenerateTau_root(NumericVector U, NumericVector t, double a, int d)
{

  NumericVector rang(2);
  rang[0]= 1;
  rang[1]= R_PosInf;

  double sec;
  int siz= t.size();
  NumericVector help1(siz);
  NumericVector help2(siz-1);
  NumericVector value(1);

  for(int j = 0; j < d; ++j)
  {
    if(j==0)
    {
      help1= t;
      help1.erase(0);

      sec= log(U[0]);
      help2= help1;
      for(int k = 1; k < d; ++k)
      {
        if(k<d-1) help2[k]= help2[k]*help2[k-1];

        sec= sec+ log(pow(U[k],help2[k-1]));
      }

      value= Cexptr(1, a- sec, rang);
      t[0]= value[0];
    }

    else
    {
      help1= t;
      help1.erase(j-1);

      sec=0;
      help2= help1;
      NumericVector xx= help2[Rcpp::seq(0,j-1)];
      help2[j-1]= std::accumulate(xx.begin(), xx.end(), 1, std::multiplies<int>());
      for(int k = j; k < d; ++k)
      {
        if(k<d-1) help2[k]= help2[k]*help2[k-1];
        sec= sec+ log(pow(U[k],help2[k-1]));
      }

      value= Cexptr(1, a- sec, rang);
      t[j]= value[0];
    }
  }
  return t;

}
