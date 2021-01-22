function (x, pi, k, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["expZ_weib_C"]][[length(e[["expZ_weib_C"]]) + 1]] <- list(x = x, 
        pi = pi, k = k, lambda = lambda)
    .Call("_mixR_expZ_weib_C", x, pi, k, lambda)
}
