function (x, pi, alpha, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglik_gamma_C"]][[length(e[["loglik_gamma_C"]]) + 1]] <- list(x = x, 
        pi = pi, alpha = alpha, lambda = lambda)
    .Call("_mixR_loglik_gamma_C", x, pi, alpha, lambda)
}
