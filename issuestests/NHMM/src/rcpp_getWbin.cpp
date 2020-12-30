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
Rcpp::NumericVector rcpp_getWbin(Rcpp::NumericVector z, int K, int J)
{  int T=z.size();
   
   Rcpp::NumericVector Wbin1(K*T*J);   //reset to zero
   for( int k = 0; k < K; k++ )
   {  for( int j = 0; j < J; j++ )
      {  for( int t = 0; t < T; t++ )
         {  if((z(t)-1)==k){ Wbin1(rcpp_3d(k,t,j,K,T,J))=1;}
            else{ Wbin1(rcpp_3d(k,t,j,K,T,J))=0; }
         }
      }
   }
   return Wbin1;
}
