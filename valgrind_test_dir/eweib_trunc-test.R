function (a, b, k, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["eweib_trunc"]][[length(e[["eweib_trunc"]]) + 1]] <- list(a = a, 
        b = b, k = k, lambda = lambda)
    .Call("_mixR_eweib_trunc", a, b, k, lambda)
}
