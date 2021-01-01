testlist <- list(nLoci = 889924430L, Prof1 = c(2051319948L, 183851356L, 600611799L,  -2015925719L, 640758675L, -2045256755L), Prof2 = c(-1294723540L,  NA))
result <- do.call(relSim:::IBS_Caller,testlist)
str(result)