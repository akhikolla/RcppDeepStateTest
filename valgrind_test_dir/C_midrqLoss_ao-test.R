function (b, G, x, yo, offset, type, tau, lambda, n, p, k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_midrqLoss_ao"]][[length(e[["C_midrqLoss_ao"]]) + 1]] <- list(b = b, 
        G = G, x = x, yo = yo, offset = offset, type = type, 
        tau = tau, lambda = lambda, n = n, p = p, k = k)
    .Call("_Qtools_C_midrqLoss_ao", b, G, x, yo, offset, type, 
        tau, lambda, n, p, k)
}
