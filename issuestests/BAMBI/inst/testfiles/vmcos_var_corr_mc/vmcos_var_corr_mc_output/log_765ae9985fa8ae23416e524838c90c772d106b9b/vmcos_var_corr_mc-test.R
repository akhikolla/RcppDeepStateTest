testlist <- list(k1 = -4.75933132109757e-131, k2 = 2.97932273417511e+301,      k3 = 1.22342204724769e+185, ncores = 1895363168L, uni_rand = c(1.4734e-38,      9.4988e-225, 7.8934e-74, -3.3506e-295))
result <- do.call(BAMBI:::vmcos_var_corr_mc,testlist)
str(result)