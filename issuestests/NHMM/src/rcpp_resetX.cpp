#include <Rcpp.h>
using namespace Rcpp;

// Below is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar)

// For more on using Rcpp click the Help button on the editor toolbar

// [[Rcpp::export]]
Rcpp::NumericMatrix rcpp_resetX(Rcpp::NumericMatrix XXf, Rcpp::NumericMatrix zbinf) 
{   int Tf=zbinf.nrow();
    int Kf=zbinf.ncol();
    int Lf=XXf.ncol();
    Rcpp::NumericMatrix XX2(Tf,Lf);
    
    
       for (int k = 0; k < Lf; k++)
       {  if(k < Kf)
          {   XX2(0,k)=XXf(0,k);
              for (int t = 0; t < Tf; t++)
              {  XX2(t+1,k)=zbinf(t,k);
              }
          }else{
              for (int t = 0; t < Tf; t++)
              {  XX2(t,k)=XXf(t,k);
              }
          }
       }
   return XX2;
}
