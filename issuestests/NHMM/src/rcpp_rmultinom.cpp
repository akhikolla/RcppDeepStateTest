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
#include "rcpp_sumv.h"
using namespace Rcpp;


// [[Rcpp::export]]
    int rcpp_rmultinom(Rcpp::NumericVector probs )
    {   int Kf = probs.size();
        int v;
        double x( 1 );
        x=runif(1)(0);    //x=runifdouble();
        Rcpp::NumericVector probsum( Kf ); //cumsum of normalized probs
        double sprob=rcpp_sumv(probs);  //sum of the probs vector
        
        probs(0)=probs(0)/sprob; 
        probsum( 0 )= probs( 0 ); 
        for( int k = 1; k < Kf; k++ )
        {  probs(k)=probs(k)/sprob;    // Normalize the probs vector
           probsum(k)=probs(k)+probsum(k-1);
        }
        if( x < probsum(0) ){ v=0; }
        
        for( int k = 0; k < (Kf-1); k++ )
        {  if((x > probsum(k)) & (x< probsum(k+1))){v=k+1;} 
        }
        if(x > probsum(Kf-1)){v=Kf-1;}
        
        return v+1;
   }
