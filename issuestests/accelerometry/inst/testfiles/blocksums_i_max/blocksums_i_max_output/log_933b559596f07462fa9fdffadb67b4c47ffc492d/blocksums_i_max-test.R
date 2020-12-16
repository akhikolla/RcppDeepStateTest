testlist <- list(window = -1400832433L, x = c(NA, -1444618827L, -281834798L,  1652982968L, -313745440L, 367953187L, 1073223132L, -1550285865L,  -1666481241L, -1610067569L))
result <- do.call(accelerometry:::blocksums_i_max,testlist)
str(result)