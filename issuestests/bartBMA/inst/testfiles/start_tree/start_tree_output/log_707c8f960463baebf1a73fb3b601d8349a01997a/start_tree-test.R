testlist <- list(start_mean = -3.59872877491565e+296, start_sd = 9.11343224192607e-239)
result <- do.call(bartBMA:::start_tree,testlist)
str(result)