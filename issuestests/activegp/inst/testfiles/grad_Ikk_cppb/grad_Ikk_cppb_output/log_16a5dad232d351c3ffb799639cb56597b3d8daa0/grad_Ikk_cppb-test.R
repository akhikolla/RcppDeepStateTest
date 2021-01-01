testlist <- list(a = -5.84486017509076e+130, b = 7.96752110805863e+95, ct = 1898225516L,      t = -4.40542167393296e-65)
result <- do.call(activegp:::grad_Ikk_cppb,testlist)
str(result)