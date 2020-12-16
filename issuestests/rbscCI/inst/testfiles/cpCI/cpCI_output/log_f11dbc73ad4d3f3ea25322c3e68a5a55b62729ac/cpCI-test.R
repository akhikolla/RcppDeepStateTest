testlist <- list(conf = 2.00490716449826e-201, n_suc = 1819959014L, n_tot = 1168997245L)
result <- do.call(rbscCI::cpCI,testlist)
str(result)