function (a, b, alpha, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["egamma_trunc"]][[length(e[["egamma_trunc"]]) + 1]] <- list(a = a, 
        b = b, alpha = alpha, lambda = lambda)
    .Call("_mixR_egamma_trunc", a, b, alpha, lambda)
}
