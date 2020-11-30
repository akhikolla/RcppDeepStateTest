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
 
 //library(msm)  #rtnorm 
 

double rtnormU(double muf, double sigf, double upf)
{   double draw;
    draw=upf+1;
         while(draw > upf) 
         {    draw=rnorm(1, muf, sigf)(0);  
         }
    return draw;
}

double rtnormL(double muf, double sigf, double lowf)
{        double draw; 
         draw= lowf-1;
         while(draw < lowf ) 
         {    draw=rnorm(1, muf, sigf)(0);
         }
         return draw;
}

double rtnormUL(double muf, double sigf, double lowf, double upf)
{        double draw;
         draw=lowf-1;
         while( draw <lowf || draw > upf) 
         {    draw=rnorm(1, muf, sigf)(0);
         }
         return draw;
}

// [[Rcpp::export]]
Rcpp::NumericVector Crtnorm(int a, Rcpp::NumericVector muf, Rcpp::NumericVector sigf, Rcpp::NumericVector lowf, Rcpp::NumericVector upf, Rcpp::NumericVector boolowf, Rcpp::NumericVector booupf )
{   Rcpp::NumericVector draws(a);

         for (int i = 0; i < a; i++) 
         {    if(boolowf(i)==0) 
              {   if(booupf(i)==0) { draws(i)=rnorm(1, muf(i), sigf(i))(0);} 
                  else             { draws(i)=rtnormU( muf(i), sigf(i), upf(i));}
              }       
              else
              {  if(booupf(i)==0)  { draws(i)=rtnormL( muf(i), sigf(i), lowf(i));} 
                     else          { draws(i)=rtnormUL( muf(i), sigf(i),lowf(i), upf(i));}
              }
         }
    return draws;
}
