function (pi, alpha, lambda, ex) 
{
    e <- get("data.env", .GlobalEnv)
    e[["TXgamma_C"]][[length(e[["TXgamma_C"]]) + 1]] <- list(pi = pi, 
        alpha = alpha, lambda = lambda, ex = ex)
    .Call("_mixR_TXgamma_C", pi, alpha, lambda, ex)
}
