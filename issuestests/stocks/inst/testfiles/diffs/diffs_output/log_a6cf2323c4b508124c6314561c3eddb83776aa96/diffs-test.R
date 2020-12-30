testlist <- list(lag = -1608321830L, x = c(Inf, NA))
result <- do.call(stocks::diffs,testlist)
str(result)