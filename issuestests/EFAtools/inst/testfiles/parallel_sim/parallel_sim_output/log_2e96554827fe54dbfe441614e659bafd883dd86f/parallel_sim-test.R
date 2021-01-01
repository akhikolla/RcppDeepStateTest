testlist <- list(eigen_type = 603497922L, maxit = -2065975987L, n_datasets = -498905818L,      n_vars = 569042049L, N = 1273656994L)
result <- do.call(EFAtools:::parallel_sim,testlist)
str(result)