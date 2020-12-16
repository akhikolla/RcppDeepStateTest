testlist <- list(k1 = 2.15906176100362e-172, k2 = 7.7558092851133e+264, k3 = -1.51831964508925e+212,      ncores = 675427161L, uni_rand = c(5.5854e+75, -4.4294e-150,      -1.9158e+90, 3.3062e+164, -2.319e+229, 7.2367e-273, 6.0564e+209,      -2.3673e+252))
result <- do.call(BAMBI:::d_const_vmcos_mc,testlist)
str(result)