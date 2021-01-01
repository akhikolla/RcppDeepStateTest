testlist <- list(iLag = 467495432L)
result <- do.call(DriftBurstHypothesis:::HACWeightC,testlist)
str(result)