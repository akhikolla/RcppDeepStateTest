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
#include "rcpp_rdirichlet.h"
#include "rcpp_3d.h"
using namespace Rcpp;

   
// [[Rcpp::export]]
Rcpp::NumericVector rcpp_getQQ(int K, Rcpp::NumericVector z, Rcpp::NumericMatrix dirprior, Rcpp::NumericVector subseqy)   
{  int T=z.size(); 
   Rcpp::NumericVector QQ(K*K*T);
   Rcpp::NumericMatrix nn(K,K);
   Rcpp::NumericMatrix QQ1(K,K);
  
   for(int i = 0; i < K; i++)
   {  for(int j = 0; j < K; j++)
      {  nn(i,j)=0;
      }
   }
   for (int t = 0; t < (T-1); t++)
   {   if(subseqy(t)==subseqy(t+1))
        {  nn(z(t)-1,z(t+1)-1)=nn(z(t)-1,z(t+1)-1)+1;
        }
   }
  
  for (int k = 0; k < K; k++)
  {    QQ1(k,_)=rcpp_rdirichlet(nn(k,_)+dirprior(k,_));        
  }
  for (int k = 0; k < K; k++)
  {  for (int j = 0; j < K; j++)
     {  for (int t = 0; t < T; t++)
        {  QQ(rcpp_3d(k,j,t,K,K,T))=QQ1(k,j);   //QQ same for all t
        }
     }
  }
  return QQ;
}

