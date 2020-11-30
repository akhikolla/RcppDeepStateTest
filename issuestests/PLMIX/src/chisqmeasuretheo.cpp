# include <Rcpp.h>
# include "fittingmeasure.h"
using namespace Rcpp;
///' Chi-squared index relying on paired comparisons for replicated data
///'
///'
///' @param N Number of sample units.
///' @param ref_order Numeric \eqn{G}\eqn{\times}{x}\eqn{K} matrix of component-specific reference orders.
///' @param p Numeric \eqn{G}\eqn{\times}{x}\eqn{K} matrix of component-specific support parameters.
///' @param weights Numeric vector of the \eqn{G} mixture weights.
///' @param pi_inv_obs Numeric \eqn{N}\eqn{\times}{x}\eqn{K} data matrix of partial orderings (to replicate the observed missingness patterns).
///' @return Chi-squared index value.
// [[Rcpp::export]]
double chisqmeasuretheo(int N, Rcpp::NumericMatrix ref_order, Rcpp::NumericMatrix p, Rcpp::NumericVector weights, Rcpp::IntegerMatrix pi_inv_obs){

    double f = 0.0 ;
       int K = p.ncol();
       int G = p.nrow();
       int slot ;
       int slot2 ;
       int g ;

       Rcpp::IntegerMatrix pi_inv(N,K);
       Rcpp::IntegerMatrix tau_mat(K,K);
       Rcpp::NumericMatrix tau_star_mat(K,K);
       Rcpp::IntegerMatrix T_mat(K,K);

       Rcpp::NumericVector marg_p(K); 



       for(slot=0; slot<K; slot++){
          for(g=0; g<G; g++){
	 marg_p[slot] = marg_p[slot] + weights[g]*p(g,slot) ;
          }
       }

       pi_inv = PLMIXsim(N, K, G, p, ref_order, weights, false, pi_inv_obs) ;

       tau_mat = tau(pi_inv); 
       for(slot=0; slot<K; slot++){
         for(slot2=0; slot2<slot; slot2++){
	   T_mat(slot,slot2) = tau_mat(slot,slot2) + tau_mat(slot2,slot);
	   T_mat(slot2,slot) = T_mat(slot,slot2) ;
	   tau_star_mat(slot,slot2) = ((double) T_mat(slot,slot2))*marg_p[slot]/(marg_p[slot]+marg_p[slot2]);
       if(tau_star_mat(slot,slot2)>0.0){
	   f = f + (((double) tau_mat(slot,slot2))-tau_star_mat(slot,slot2))*(((double) tau_mat(slot,slot2))-tau_star_mat(slot,slot2))/(tau_star_mat(slot,slot2));
       }
	 }
       }

       return f;  

}
