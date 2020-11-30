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
Rcpp::NumericMatrix rcpp_getsumz1(int Kf,  int Jf, int Tf, Rcpp::NumericVector zf, Rcpp::NumericVector Sigmainvf, Rcpp::NumericMatrix in2f )
   {   Rcpp::NumericMatrix  sumz1f(Jf,Jf);
       for (int tt = 0; tt < Tf; tt++)
       {   for (int j = 0; j < Jf; j++)
           {   for (int i = 0; i < Jf; i++)
               {  sumz1f(j,i)=sumz1f(j,i)+Sigmainvf(rcpp_3d(j,i,zf(tt), Jf,Jf,Kf))*in2f(tt,j)*in2f(tt,i);
               }
           }
       }
       return sumz1f;
   }
