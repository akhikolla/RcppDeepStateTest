testlist <- list(accuracy = 8.2390922993911e+275, m = 484058222L, px = -2.43318023382663e-187,      py = -1.64581369299083e+174, T_observed = 2.17590117142795e+276)
result <- do.call(jaccard:::jaccard_mca_rcpp_known_p,testlist)
str(result)