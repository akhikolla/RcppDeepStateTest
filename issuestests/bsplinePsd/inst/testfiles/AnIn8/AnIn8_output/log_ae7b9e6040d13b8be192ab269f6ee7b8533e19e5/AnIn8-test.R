testlist <- list(knot = c(NA, 2.53818887794571e+207, -Inf))
result <- do.call(bsplinePsd:::AnIn8,testlist)
str(result)