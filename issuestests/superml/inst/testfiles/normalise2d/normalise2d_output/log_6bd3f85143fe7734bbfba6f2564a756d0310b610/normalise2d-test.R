testlist <- list(axis = -879953637L, mat = structure(c(NA, -Inf, -Inf, NA,  -Inf, 1.55275352858005e+40), .Dim = c(1L, 6L)), pnorm = 1649522050L)
result <- do.call(superml::normalise2d,testlist)
str(result)