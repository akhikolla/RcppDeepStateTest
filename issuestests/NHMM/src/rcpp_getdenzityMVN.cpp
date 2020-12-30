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
#include "rcpp_3d.h"
#include "rcpp_sumv.h"
#include "rcpp_prod.h"
#include "rcpp_getWbin.h"
#include "rcpp_dmvnorm.h"
#include "rcpp_arraytomat.h"
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::NumericMatrix rcpp_getdenzityMVN(int A, Rcpp::NumericVector Wbin, Rcpp::NumericMatrix psi, int K, Rcpp::NumericMatrix y, Rcpp::NumericVector thetainv,Rcpp::NumericVector detS)
{      
    int T = y.nrow();
    int J = y.ncol();
    Rcpp::NumericMatrix denzity(K,T);
    
    Rcpp::NumericVector zz(T);
    Rcpp::NumericVector Wbin1(A*T*J);
    Rcpp::NumericMatrix mus(T,J);
    Rcpp::NumericMatrix siginv(J,J);
    
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

      for(int tt = 0; tt < T; tt++ )
      {   siginv=rcpp_arraytomat(thetainv,k,J,J,K);
          denzity(k,tt)=rcpp_dmvnorm(y(tt,_),mus(tt,_), siginv , detS(k));  
      }
  }
  return denzity;
 
}
