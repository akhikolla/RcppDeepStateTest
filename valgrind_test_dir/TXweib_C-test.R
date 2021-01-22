function (pi, k, lambda, ex) 
{
    e <- get("data.env", .GlobalEnv)
    e[["TXweib_C"]][[length(e[["TXweib_C"]]) + 1]] <- list(pi = pi, 
        k = k, lambda = lambda, ex = ex)
    .Call("_mixR_TXweib_C", pi, k, lambda, ex)
}
