function (x, pi, mulog, sdlog) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglik_lnorm_C"]][[length(e[["loglik_lnorm_C"]]) + 1]] <- list(x = x, 
        pi = pi, mulog = mulog, sdlog = sdlog)
    .Call("_mixR_loglik_lnorm_C", x, pi, mulog, sdlog)
}
