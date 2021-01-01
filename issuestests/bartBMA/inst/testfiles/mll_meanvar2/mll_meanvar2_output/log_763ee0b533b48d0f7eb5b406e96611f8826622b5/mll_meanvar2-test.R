testlist <- list(n = -916522979L, x = -3.59872877491565e+296, x2 = 9.11343224192607e-239)
result <- do.call(bartBMA:::mll_meanvar2,testlist)
str(result)