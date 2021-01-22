function (mu, alpha, zetas, fi, ti) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CBMNLLInner"]][[length(e[["CBMNLLInner"]]) + 1]] <- list(mu = mu, 
        alpha = alpha, zetas = zetas, fi = fi, ti = ti)
    .Call("_RJafroc_CBMNLLInner", PACKAGE = "RJafroc", mu, alpha, 
        zetas, fi, ti)
}
