testlist <- list(k = 4.2913428360563e+257, mu = 2.13936278438989e-92, n = -164577095L)
result <- do.call(BAMBI:::runivm_onepar,testlist)
str(result)