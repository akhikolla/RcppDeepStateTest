testlist <- list(n = -2.43318023382663e-187)
result <- do.call(KSgeneral:::ks_c_cdf_Rcpp,testlist)
str(result)