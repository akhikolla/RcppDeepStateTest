testlist <- list(from = 2.46667859116869e-86, length = 2.59435238785996e+241,      to = 2.28393946356129e-55)
result <- do.call(biClassify:::LambdaSeqCpp,testlist)
str(result)