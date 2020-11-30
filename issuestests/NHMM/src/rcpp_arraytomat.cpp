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
Rcpp::NumericMatrix rcpp_arraytomat(Rcpp::NumericVector arr3d, int c, int A, int B, int C) 
{
   Rcpp::NumericMatrix mattime(A,B);
   for (int a = 0; a < A; a++) 
   {  for (int b = 0; b < B; b++) 
      {  mattime(a,b)=arr3d(rcpp_3d(a,b,c,A,B,C));
      }
   }
  
   return mattime;
}
