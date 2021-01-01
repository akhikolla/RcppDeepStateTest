testlist <- list(a = -8.51189803621161e-07, b = -5.48117317547102e-145, ct = 805659460L,      t = 4.79212291154048e-250)
result <- do.call(activegp:::grad_w_ij_cppb,testlist)
str(result)