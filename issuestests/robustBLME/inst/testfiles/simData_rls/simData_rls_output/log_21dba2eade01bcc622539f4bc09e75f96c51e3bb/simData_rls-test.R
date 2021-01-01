testlist <- list(mu = -2.43318023382663e-187, n = 484058222L, sig = -1.64581369299083e+174)
result <- do.call(robustBLME:::simData_rls,testlist)
str(result)