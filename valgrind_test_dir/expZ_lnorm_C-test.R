function (x, pi, mulog, sdlog) 
{
    e <- get("data.env", .GlobalEnv)
    e[["expZ_lnorm_C"]][[length(e[["expZ_lnorm_C"]]) + 1]] <- list(x = x, 
        pi = pi, mulog = mulog, sdlog = sdlog)
    .Call("_mixR_expZ_lnorm_C", x, pi, mulog, sdlog)
}
