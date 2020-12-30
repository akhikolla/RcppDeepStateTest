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
Rcpp::NumericVector rcpp_rdirichlet(Rcpp::NumericVector B)
{  int nb=B.size();
   Rcpp::NumericVector draw(nb);
   double draws;
  
   for (int i = 0; i < nb; i++)
   {  draw(i)=rgamma(nb,B(i),1.0)(0);
      draws=draws+draw(i);
   }
   for (int i = 0; i < nb; i++)
   {  draw(i)=draw(i)/draws;
   }
   return draw;
}
