#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector weighted_kaplan_meier(Rcpp::NumericMatrix response, 
            Rcpp::NumericVector weights, Rcpp::NumericVector timepoints) {
              
  size_t n = response.nrow();             
  size_t num_timepoints = timepoints.length();            
              
  // Compute at risk for each timepoint
  Rcpp::NumericVector at_risk(num_timepoints);
  for (size_t i = 0; i < n; ++i) {
    size_t j = 0;
    double survival_time = response(i, 0);
    while(j < num_timepoints && survival_time >= timepoints(j)) {
      at_risk(j) += weights(i);
      ++j;
    }
  }  
  
  // Compute deaths for each timepoint
  Rcpp::NumericVector death(num_timepoints);
  for (size_t i = 0; i < n; ++i) {
    if (response(i, 1) == 1) {
      double survival_time = response(i, 0);
      for(size_t j = 0; j < num_timepoints; ++j) {
        if (survival_time == timepoints(j)) {
          death(j) += weights(i);
          break;
        }
      }
    }
  } 
  
  // Compute survival prediction
  Rcpp::NumericVector survival(num_timepoints);
  if (at_risk(0) > 0) {
    survival(0) = 1 - death(0)/at_risk(0);
  }
  for (size_t j = 1; j < num_timepoints; ++j) {
    survival(j) = survival(j-1);
    if (at_risk(j) > 0) {
      survival(j) *= (1 - death(j)/at_risk(j));
    }
  }

  return survival;
}


