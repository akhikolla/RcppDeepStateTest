function (data, pi, alpha, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglik_gamma_g_C"]][[length(e[["loglik_gamma_g_C"]]) + 
        1]] <- list(data = data, pi = pi, alpha = alpha, lambda = lambda)
    .Call("_mixR_loglik_gamma_g_C", data, pi, alpha, lambda)
}
