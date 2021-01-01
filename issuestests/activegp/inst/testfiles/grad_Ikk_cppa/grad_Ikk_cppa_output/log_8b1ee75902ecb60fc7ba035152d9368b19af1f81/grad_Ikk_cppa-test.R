testlist <- list(a = 3165220.77664468, b = 3.72125709439662e-82, ct = 1586657384L,      t = 5.29799276156047e-243)
result <- do.call(activegp:::grad_Ikk_cppa,testlist)
str(result)