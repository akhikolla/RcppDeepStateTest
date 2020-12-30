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
Rcpp::NumericVector rcpp_getsumz2(int llf, int LLf,int Kf, int Jf, int Tf, Rcpp::NumericVector zf, Rcpp::NumericVector Sigmainvf, Rcpp::NumericVector in2f,  Rcpp::NumericMatrix yf, Rcpp::NumericMatrix betaemf , Rcpp::NumericMatrix betaem0f)
   {   Rcpp::NumericVector  sumz2f(Jf);
       Rcpp::NumericVector  Y2(Jf);
       Rcpp::NumericVector  adds(Jf);

      for (int tt = 0; tt < Tf; tt++)
      {     
         for(int j=0; j < Jf; j++)
         {   adds(j)=0;
             for (int mm = 0; mm < LLf; mm++)
             {   if(mm != (llf-1)){ adds(j)=adds(j)+betaemf(j,mm)*in2f(rcpp_3d(mm,tt,j,LLf,Tf,Jf));  }
             }
             Y2(j)=yf(tt,j)-betaem0f(zf(tt),j)-adds(j);
         }
         for(int j=0; j < Jf; j++)
         {   for(int i=0; i < Jf; i++)
             {  sumz2f(j)=sumz2f(j)+ Y2(i)* Sigmainvf(rcpp_3d(i,j,zf(tt), Jf,Jf,Kf))* in2f(rcpp_3d(llf-1,tt,j,LLf,Tf,Jf));
             }
         }
      }

       return sumz2f;
   }
