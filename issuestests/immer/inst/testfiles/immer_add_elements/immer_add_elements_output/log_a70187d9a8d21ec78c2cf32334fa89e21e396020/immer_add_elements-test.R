testlist <- list(h = -1.22319427934351e+213, pos = 1717734276L, x = c(Inf,  1.696243369264e+41, -2.4816735654344e-141, Inf, 4.5497266574123e+33,  NA, 0))
result <- do.call(immer:::immer_add_elements,testlist)
str(result)