testlist <- list(a = -2.43318023382663e-187, b = -1.64581369299083e+174,      ct = 1668042617L, t = -1.66667893622001e-49)
result <- do.call(activegp:::grad_w_ii_cppb,testlist)
str(result)