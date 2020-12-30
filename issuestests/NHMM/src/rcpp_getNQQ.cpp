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
using namespace Rcpp;



   
 // [[Rcpp::export]]
Rcpp::NumericVector rcpp_getNQQ(Rcpp::NumericMatrix beta, Rcpp::NumericMatrix XX) 
{  int T=XX.nrow();
   int K=beta.nrow();
   int L=XX.ncol();
   Rcpp::NumericVector QQf(K*K*T);
   Rcpp::NumericVector epsi(K*K*T);
   double dots;
   double one;
   Rcpp::NumericMatrix epsi2(K,T);

   for( int t = 0; t < T; t++ )
   { for( int k = 0; k < K; k++ )
     {   
         for( int j = 0; j < K; j++ )
         {  dots=0;
            for( int h = K; h < L; h++ )
            {  dots = dots + beta(j,h) * XX(t,h);
            } 
            one=exp(beta(j,k)+ dots);
            epsi2(k,t)=epsi2(k,t)+one;
            epsi(rcpp_3d(k,j,t,K,K,T))=one;
         }
         for( int j = 0; j < K; j++ )
         {   QQf(rcpp_3d(k,j,t,K,K,T))=epsi(rcpp_3d(k,j,t,K,K,T))/epsi2(k,t);
         }
     }
   }
 
   return QQf;
}

