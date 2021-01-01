testlist <- list(pair_x = 1078897549L, pair_y = -289987065L, X = structure(c(2.58035513749295e-206,  -Inf, NaN), .Dim = c(1L, 3L)))
result <- do.call(xyz:::scale_intr,testlist)
str(result)