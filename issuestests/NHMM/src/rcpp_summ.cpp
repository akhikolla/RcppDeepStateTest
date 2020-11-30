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
   double rcpp_summ(Rcpp::NumericMatrix A)
   {     int T = A.nrow();
         int J = A.ncol();
         double b=0;
         for (int i = 0; i < T; i++)
         {  for (int j = 0; j < J; j++)
            {  b=b+A(i,j);
            }
         }
         return b;
   }
