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
#include "rcpp_pnorm.h"
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_getppp(Rcpp::NumericMatrix gamy, Rcpp::NumericMatrix mus)
{
    int mixes=gamy.nrow()-1; 
    int T = mus.nrow();
    int J = mus.ncol();
    Rcpp::NumericVector ppp(T*J*mixes);
    double addit;
  
  if(mixes == 1)   //mixes of 1 or 2
  {   for( int j = 0; j < J; j++ )
      {   for( int t = 0; t < T; t++ )
          {   ppp(rcpp_3d(t,j,0,T,J,mixes))=1; 
          }
      }
  }
  if(mixes == 2)   //mixes of 1 or 2
  {   for( int j = 0; j < J; j++ )
      {   for( int t = 0; t < T; t++ )
          {   ppp(rcpp_3d(t,j,0,T,J,mixes))=rcpp_pnorm(gamy(1,j)-mus(t,j)); 
              ppp(rcpp_3d(t,j,1,T,J,mixes))=1-ppp(rcpp_3d(t,j,0,T,J,mixes));  //last ppp
          }
      }
  }
  if(mixes>2)
  {   for( int j = 0; j < J; j++ )
      {   for( int t = 0; t < T; t++ )
          {   ppp(rcpp_3d(t,j,0,T,J,mixes))=rcpp_pnorm(gamy(1,j)-mus(t,j));
              addit=0;
              for( int v = 1; v < (mixes-1); v++ )
              { addit= addit+ppp(rcpp_3d(t,j,v-1,T,J,mixes));
                ppp(rcpp_3d(t,j,v,T,J,mixes))=rcpp_pnorm(gamy(v+1,j)-mus(t,j))-addit;
              }
              addit=addit+ppp(rcpp_3d(t,j,mixes-2,T,J,mixes));
              ppp(rcpp_3d(t,j,mixes-1,T,J,mixes))=1-addit; //last ppp
          }
      }
  }
  return ppp;
} 
