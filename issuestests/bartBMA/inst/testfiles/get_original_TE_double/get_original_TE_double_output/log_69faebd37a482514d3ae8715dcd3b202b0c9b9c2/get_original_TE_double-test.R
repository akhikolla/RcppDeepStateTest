testlist <- list(high = -5.48117317547102e-145, low = -8.51189803621161e-07,      sp_high = 9.60637084360072e+283, sp_low = 4.79212291154048e-250,      sum_preds = 5.0046257437231e-274)
result <- do.call(bartBMA:::get_original_TE_double,testlist)
str(result)