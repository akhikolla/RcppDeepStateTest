function (variance, dim = 1L, n_iter = -1L, finalTime = -1, x0 = numeric(0), 
    v0 = numeric(0)) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ZigZagIIDGaussian"]][[length(e[["ZigZagIIDGaussian"]]) + 
        1]] <- list(variance = variance, dim = dim, n_iter = n_iter, 
        finalTime = finalTime, x0 = x0, v0 = v0)
    .Call("_RZigZag_ZigZagIIDGaussian", PACKAGE = "RZigZag", 
        variance, dim, n_iter, finalTime, x0, v0)
}
