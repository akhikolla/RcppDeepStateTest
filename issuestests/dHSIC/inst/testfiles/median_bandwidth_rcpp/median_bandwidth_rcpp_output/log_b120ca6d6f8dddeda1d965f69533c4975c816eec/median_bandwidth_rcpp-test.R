testlist <- list(d = 1485040860L, n = 88940557L, x = structure(c(Inf, -Inf,  2.46562043224079e-85, NaN, 1.78433108967668e+169), .Dim = c(5L,  1L)))
result <- do.call(dHSIC:::median_bandwidth_rcpp,testlist)
str(result)