testlist <- list(conf = -3.76893659726935e+192, n_suc = 472719877L, n_tot = 1114625845L)
result <- do.call(rbscCI::bscCI,testlist)
str(result)