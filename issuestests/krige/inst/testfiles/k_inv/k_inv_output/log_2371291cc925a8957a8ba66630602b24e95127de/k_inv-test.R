testlist <- list(GlobalMat = structure(c(NA, Inf, 1.57546125271901e-262,  -6.768064057128e+55, -Inf, 9.456787015987e+166), .Dim = c(6L,  1L)))
result <- do.call(krige:::k_inv,testlist)
str(result)