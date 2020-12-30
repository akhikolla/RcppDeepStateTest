//////////////////////////////////////////////////////////////
// Copyright 2014 Tracy Holsclaw.

// This file is part of NHMM.

// NHMM is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or any later version.

// NHMM is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along with
// NHMM.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////
#include <Rcpp.h>
#include "rcpp_summ.h"
#include "rcpp_3d.h"
#include "rcpp_rdmix0.h"
using namespace Rcpp;


// [[Rcpp::export]]

Rcpp::NumericMatrix rcpp_getymiss(int fam, int K, Rcpp::NumericVector z, Rcpp::NumericVector ppp, Rcpp::NumericVector  theta1,  Rcpp::NumericVector  theta2, int mixes, int delt, int J)
{   int T = z.size();
    int md=mixes-delt;
    Rcpp::NumericVector ps(mixes);
    Rcpp::NumericVector th1(md);   //0- FALSE, 1-TRUE
    Rcpp::NumericVector th2(md);
    Rcpp::NumericMatrix yy(T,J);
    
      for( int j = 0; j < J; j++ )
      {  for( int t = 0; t < T; t++ )
         {   for( int i = 0; i < mixes; i++ )
             {  ps(i)=ppp(rcpp_3d(t,j,i,T,J,mixes));
             }
       
             for( int i = 0; i < md; i++ )
             {   th1(i) = theta1(rcpp_3d(i,z(t)-1,j,md,K,J));
                 th2(i) = theta2(rcpp_3d(i,z(t)-1,j,md,K,J));
             }
           
             if(delt==0){yy(t,j)=rcpp_rmix(fam,ps,th1,th2);} 
             if(delt==1){yy(t,j)=rcpp_rmix0(fam,ps,th1,th2);} 
             
             if(yy(t,j)<0.1 && yy(t,j)> -0.1 && delt==1){yy(t,j)=0;}  //problem line for delt==0
                                          //if(yy(t,j)<0.1 && delt==1)  {yy(t,j)=0;} 
         }
      }
    return yy;
}
