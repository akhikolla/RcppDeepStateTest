function (x, pi, k, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglik_weib_C"]][[length(e[["loglik_weib_C"]]) + 1]] <- list(x = x, 
        pi = pi, k = k, lambda = lambda)
    .Call("_mixR_loglik_weib_C", x, pi, k, lambda)
}
