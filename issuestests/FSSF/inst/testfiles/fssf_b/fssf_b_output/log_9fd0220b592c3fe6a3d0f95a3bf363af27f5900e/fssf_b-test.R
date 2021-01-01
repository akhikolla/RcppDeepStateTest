testlist <- list(d = -498905818L, eps = 2.30186283720217e+66, N = 1273656994L,      nMax = 569042049L)
result <- do.call(FSSF:::fssf_b,testlist)
str(result)