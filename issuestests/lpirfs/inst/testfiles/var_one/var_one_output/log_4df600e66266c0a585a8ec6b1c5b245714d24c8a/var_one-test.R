testlist <- list(VAR_Data = structure(c(NA, -Inf, -Inf, NA, -Inf, 1.55275352858005e+40 ), .Dim = c(1L, 6L)))
result <- do.call(lpirfs:::var_one,testlist)
str(result)