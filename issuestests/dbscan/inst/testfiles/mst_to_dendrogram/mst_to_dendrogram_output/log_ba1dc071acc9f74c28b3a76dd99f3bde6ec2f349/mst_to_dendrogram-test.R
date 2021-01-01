testlist <- list(mst = structure(c(Inf, -Inf, 2.46562043224079e-85, NaN,  1.78433108967668e+169), .Dim = c(5L, 1L)))
result <- do.call(dbscan:::mst_to_dendrogram,testlist)
str(result)