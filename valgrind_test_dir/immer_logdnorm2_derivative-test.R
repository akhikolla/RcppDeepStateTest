function (x, y, mu1, mu2, var1, var2, cov12) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_logdnorm2_derivative"]][[length(e[["immer_logdnorm2_derivative"]]) + 
        1]] <- list(x = x, y = y, mu1 = mu1, mu2 = mu2, var1 = var1, 
        var2 = var2, cov12 = cov12)
    .Call("_immer_immer_logdnorm2_derivative", PACKAGE = "immer", 
        x, y, mu1, mu2, var1, var2, cov12)
}
