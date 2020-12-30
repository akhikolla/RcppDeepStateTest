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
#include "rcpp_rmultinom.h"
#include "rcpp_dgamma.h"
#include "rcpp_rgamma.h"
#include "rcpp_dnorm.h"
#include "rcpp_rnorm.h"
#include "rcpp_dpois.h"
#include "rcpp_rpois.h"
using namespace Rcpp;


//fam
//1- gamma
//2- normal
//3- poisson



// [[Rcpp::export]]
Rcpp::NumericVector rcpp_dmix0(int fam, double y, Rcpp::NumericVector ppp, Rcpp::NumericVector par1, Rcpp::NumericVector par2)  
{    
   int nm=ppp.size();
   Rcpp::NumericVector dd(nm);
   
   if(y==0)
   {   dd(0)=ppp(0);
   }else{
        for( int i = 1; i < nm; i++ )
        {   if(fam==1){ dd(i)=ppp(i)*rcpp_dgamma(y,par1(i-1),par2(i-1));}
            if(fam==2){ dd(i)=ppp(i)*rcpp_dnorm(y,par1(i-1),sqrt(par2(i-1)));}
            if(fam==3){ dd(i)=ppp(i)*rcpp_dpois(y,par1(i-1));}
        }
   }
   return dd;
}



// [[Rcpp::export]]
double rcpp_rmix0(int fam, Rcpp::NumericVector ppp, Rcpp::NumericVector par1, Rcpp::NumericVector par2)
{  
   int nm=ppp.size();
   double v(nm);
   v=rcpp_rmultinom(ppp)-1;
   double rr;
   
   if(v==0)
   {  rr=0;
   }else{
      if(fam==1) { rr=rcpp_rgamma(1,par1(v-1),par2(v-1));}
      if(fam==2) { rr=rcpp_rnorm(1,par1(v-1),sqrt(par2(v-1)));}
      if(fam==3) { rr=rcpp_rpois(1,par1(v-1));}
   }
   return rr;
}



// [[Rcpp::export]]  
Rcpp::NumericVector rcpp_dmix(int fam, double y, Rcpp::NumericVector ppp, Rcpp::NumericVector par1, Rcpp::NumericVector par2)  
{    
   int nm=ppp.size();
   Rcpp::NumericVector dd(nm);
   
   for( int i = 0; i < nm; i++ )
   {   if(fam==1){dd(i)=ppp(i)*rcpp_dgamma(y,par1(i),par2(i));} 
       if(fam==2){dd(i)=ppp(i)*rcpp_dnorm(y,par1(i),sqrt(par2(i)));}
       if(fam==3){dd(i)=ppp(i)*rcpp_dpois(y,par1(i));}
   }
   return dd;
}


// [[Rcpp::export]]
double rcpp_rmix(int fam, Rcpp::NumericVector ppp, Rcpp::NumericVector par1, Rcpp::NumericVector par2)
{  
   int nm=ppp.size();
   double v(nm);
   v=rcpp_rmultinom(ppp)-1;
   double rr;
   
   if(fam==1) {rr=rcpp_rgamma(1,par1(v),par2(v));}
   if(fam==2) {rr=rcpp_rnorm(1,par1(v),sqrt(par2(v)));}
   if(fam==3) {rr=rcpp_rpois(1,par1(v));}
      
   return rr;
}



