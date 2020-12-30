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
#include "rcpp_rdmix0.h"
#include "rcpp_3d.h"
#include "rcpp_sumv.h"
#include "rcpp_rmultinom.h"
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::NumericMatrix  rcpp_getvvv(int fam, int K, int mixes, int delt, Rcpp::NumericMatrix y, Rcpp::NumericVector ppp, Rcpp::NumericVector  theta1,  Rcpp::NumericVector  theta2, Rcpp::NumericVector z)   
{  
    int T = y.nrow();
    int J = y.ncol();
    Rcpp::NumericVector prob1(mixes);
    Rcpp::NumericVector ps(mixes);
    Rcpp::NumericMatrix vvv(T,J);
    int md=mixes-delt;
    Rcpp::NumericVector th1(md);   //0- FALSE, 1-TRUE
    Rcpp::NumericVector th2(md);
 
  
  for( int j = 0; j < J; j++ )
  {  for( int t = 0; t < T; t++ )
     {   
       
         for( int i = 0; i < mixes; i++ )
         {  ps(i)=ppp(rcpp_3d(t,j,i,T,J,mixes));
         }
       
          for( int i = 0; i < md; i++ )
          {   th1(i) = theta1(rcpp_3d(i,z(t)-1,j,md,K,J));
              th2(i) = theta2(rcpp_3d(i,z(t)-1,j,md,K,J));
          }
          if(delt==0){prob1=rcpp_dmix(fam,y(t,j),ps,th1,th2);} 
          if(delt==1){prob1=rcpp_dmix0(fam,y(t,j),ps,th1,th2);} 

       
         if(rcpp_sumv(prob1)==0)
         {  for( int i = 0; i < mixes; i++ )
            {  prob1(i)=1/mixes;
            }
        }
        if(fam==1||fam==3)
        { if(y(t,j)>0){ vvv(t,j)=rcpp_rmultinom(prob1)-1;}else{vvv(t,j)=0;} //starts at zero
        }
        if(fam==2){ vvv(t,j)=rcpp_rmultinom(prob1)-1;}
     }
  }
  return vvv;
}
