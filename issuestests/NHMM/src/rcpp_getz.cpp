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
#include "rcpp_rmultinom.h"
using namespace Rcpp;



   
// [[Rcpp::export]]   
void rcpp_getz(Rcpp::NumericVector zf,  Rcpp::NumericVector QQf, Rcpp::NumericMatrix denzity, Rcpp::NumericVector subseqy)
{   
     int K = denzity.nrow();
     int T = denzity.ncol();
     Rcpp::NumericVector qs(K);
     Rcpp::NumericVector pro(K);
     
       int t=0;
        for( int k = 0; k < K; k++ )
        {  qs(k)=QQf(rcpp_3d(k,zf(t+1)-1,t+1,K,K,T));
           pro(k)=denzity(k,t)*qs(k);                   //probabilities
        }
        if(rcpp_sumv(pro)==0)
        {  for( int k = 0; k < K; k++ )
           {  pro(k)=1/K;
           }
        }
        zf(t)=rcpp_rmultinom(pro);  //lf*Kf*Jf + kf*Jf + jf;
      
      
      for( int t = 1; t < (T-1); t++ )
      {  if(subseqy(t) != subseqy(t+1) )   //check for sequence breaks
         {   for( int k = 0; k < (K-1); k++ )
             {  qs(k)=QQf(rcpp_3d(zf(t-1)-1,k,t,K,K,T));
             }
         }else
         {   if(subseqy(t-1) != subseqy(t))
             {   for( int k = 0; k < (K-1); k++ )
                 {   qs(k)=QQf(rcpp_3d(k,zf(t+1)-1,t+1,K,K,T));
                 }
             }else
             {  for( int k = 0; k < (K-1); k++ )
                {  qs(k)=QQf(rcpp_3d(zf(t-1)-1,k,t,K,K,T))*QQf(rcpp_3d(k,zf(t+1)-1,t+1,K,K,T));  //no special case (majority of the time)
                }
             }  
         }   

        for( int k = 0; k < K; k++ )
        {  pro(k)=denzity(k,t)*qs(k);                   //probabilities
        }
        if(rcpp_sumv(pro)==0)
        {  for( int k = 0; k < (K-1); k++ )
           {  pro(k)=1/K;
           }
        }
        zf(t)=rcpp_rmultinom(pro); 
     }
     
        t=T-1;
        for( int k = 0; k < K; k++ )
        {  qs(k)=QQf(rcpp_3d(zf(t-1)-1,k,t,K,K,T));
           pro(k)=denzity(k,t)*qs(k);                   //probabilities
        }
        if(rcpp_sumv(pro)==0)
        {  for( int k = 0; k < K; k++ )
           {  pro(k)=1/K;
           }
        }
        zf(t)=rcpp_rmultinom(pro); 
        
     return;
     
}
