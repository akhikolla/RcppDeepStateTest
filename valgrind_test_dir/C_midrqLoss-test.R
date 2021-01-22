function (b, G, x, yo, offset, type, tau, n, p, k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_midrqLoss"]][[length(e[["C_midrqLoss"]]) + 1]] <- list(b = b, 
        G = G, x = x, yo = yo, offset = offset, type = type, 
        tau = tau, n = n, p = p, k = k)
    .Call("_Qtools_C_midrqLoss", b, G, x, yo, offset, type, tau, 
        n, p, k)
}
