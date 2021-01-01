testlist <- list(k = -1.64581369299083e+174, n = -2.43318023382663e-187)
result <- do.call(GDINA:::combnCpp,testlist)
str(result)