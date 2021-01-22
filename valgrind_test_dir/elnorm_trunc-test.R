function (a, b, mulog, sdlog) 
{
    e <- get("data.env", .GlobalEnv)
    e[["elnorm_trunc"]][[length(e[["elnorm_trunc"]]) + 1]] <- list(a = a, 
        b = b, mulog = mulog, sdlog = sdlog)
    .Call("_mixR_elnorm_trunc", a, b, mulog, sdlog)
}
