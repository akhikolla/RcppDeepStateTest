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
using namespace Rcpp;


// [[Rcpp::export]]
double rcpp_dmvnorm(Rcpp::NumericVector dataf, Rcpp::NumericVector meanf, Rcpp::NumericMatrix Siginvf, double detf )
   {     RNGScope scope;
         const double pi=3.141593;   /* pi */
         double send;
         double d = dataf.size();        /* *.size() */
  
         double four=0;
         for (int i = 0; i < d; i++) 
         {  for (int j = 0; j < d; j++) 
            {  four=four + Siginvf(i,j)*(dataf(i)-meanf(i))*(dataf(j)-meanf(j));
            }
         }                       /* pow() and exp() are touchy about 1/2 (int) and 0.5 (double) */
         send= pow(2*pi,double(-d/2))*pow(detf,0.5) *exp(-0.5*four);  
        
         return send;
   }
