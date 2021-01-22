function (pi, mulog, sdlog, ex) 
{
    e <- get("data.env", .GlobalEnv)
    e[["TXlnorm_C"]][[length(e[["TXlnorm_C"]]) + 1]] <- list(pi = pi, 
        mulog = mulog, sdlog = sdlog, ex = ex)
    .Call("_mixR_TXlnorm_C", pi, mulog, sdlog, ex)
}
