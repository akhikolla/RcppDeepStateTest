function (data, pi, mulog, sdlog) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglik_lnorm_g_C"]][[length(e[["loglik_lnorm_g_C"]]) + 
        1]] <- list(data = data, pi = pi, mulog = mulog, sdlog = sdlog)
    .Call("_mixR_loglik_lnorm_g_C", data, pi, mulog, sdlog)
}
