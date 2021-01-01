testlist <- list(alpha = -6.83209170679447e+153, Fn = 7.4551463263334e+217,      Ft = -1.17841187741978e-86, K = -7.14423384634539e-172, Tr = 1.05959360088517e-198)
result <- do.call(forestControl:::sft_calc,testlist)
str(result)