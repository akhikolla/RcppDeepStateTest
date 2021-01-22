function (data, pi, k, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglik_weib_g_C"]][[length(e[["loglik_weib_g_C"]]) + 
        1]] <- list(data = data, pi = pi, k = k, lambda = lambda)
    .Call("_mixR_loglik_weib_g_C", data, pi, k, lambda)
}
