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
#include "rcpp_prod.h"
#include "rcpp_getWbin.h"
#include "rcpp_getppp.h"
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_getdenzity(int A, Rcpp::NumericVector Wbin, Rcpp::NumericMatrix psi, Rcpp::NumericMatrix gamy, int fam, int K, int mixes, int delt, Rcpp::NumericMatrix y, Rcpp::NumericVector ppp, Rcpp::NumericVector theta1, Rcpp::NumericVector theta2)
{      
    int T = y.nrow();
    int J = y.ncol();
    Rcpp::NumericVector denzity1(J);
    Rcpp::NumericVector denzity(K*T*J);
    
    int md=mixes-delt;
    Rcpp::NumericVector th1(md);   //0- FALSE, 1-TRUE
    Rcpp::NumericVector th2(md);
    Rcpp::NumericVector ps(mixes);
    Rcpp::NumericVector zz(T);
    Rcpp::NumericVector Wbin1(A*T*J);
    Rcpp::NumericMatrix mus(T,J);
    
   for( int k = 0; k < K; k++ )
   { 
     for( int t = 0; t < T; t++ )
      {  zz(t)=k+1;
      }
      Wbin1=rcpp_getWbin(zz,K,J);  //First K rows of Wbin
      
      for( int t = 0; t < T; t++ )
      {   
          for( int j = 0; j < J; j++ )
          {   
              mus(t,j)=0;
              for( int i=0; i < K; i++)
              {  mus(t,j)= mus(t,j)+(psi(i,j)*Wbin1(rcpp_3d(i,t,j,K,T,J)));
              }
              if(A>0)    //Add covariates to mus
              {   for( int i=K; i < (K+A); i++)
                  {  mus(t,j)= mus(t,j)+(psi(i,j)*Wbin(rcpp_3d(i,t,j,A+K,T,J)));
                  }
              }
          }
      }    
      ppp=rcpp_getppp(gamy, mus);
      
      
      for( int t = 0; t < T; t++ )
      {   for( int j = 0; j < J; j++ )
          {   for( int i = 0; i < mixes; i++ )
              {  ps(i)=ppp(rcpp_3d(t,j,i,T,J,mixes));
              }
              for( int i = 0; i < md; i++ )
              {  th1(i) = theta1(rcpp_3d(i,k,j,md,K,J));
                 th2(i) = theta2(rcpp_3d(i,k,j,md,K,J));
              }
              if(delt==0){denzity1(j)=rcpp_sumv(rcpp_dmix(fam,y(t,j),ps,th1,th2));} 
              if(delt==1){denzity1(j)=rcpp_sumv(rcpp_dmix0(fam,y(t,j),ps,th1,th2));} 
              denzity(rcpp_3d(k,t,j,K,T,J))=denzity1(j); 
          }
     }
  }
  return denzity;
 
}
