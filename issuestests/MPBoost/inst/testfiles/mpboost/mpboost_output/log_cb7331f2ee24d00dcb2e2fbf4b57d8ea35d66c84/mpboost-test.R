testlist <- list(MTI = -1765421280L, N1 = 663713120L, N2 = 1816928853L)
result <- do.call(MPBoost:::mpboost,testlist)
str(result)