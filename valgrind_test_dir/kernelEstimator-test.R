function (a, b, na, q, adj, type, ab, ab2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["kernelEstimator"]][[length(e[["kernelEstimator"]]) + 
        1]] <- list(a = a, b = b, na = na, q = q, adj = adj, 
        type = type, ab = ab, ab2 = ab2)
    .Call("_highfrequency_kernelEstimator", a, b, na, q, adj, 
        type, ab, ab2)
}
