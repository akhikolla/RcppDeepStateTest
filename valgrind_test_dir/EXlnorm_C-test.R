function (data, mulog, sdlog) 
{
    e <- get("data.env", .GlobalEnv)
    e[["EXlnorm_C"]][[length(e[["EXlnorm_C"]]) + 1]] <- list(data = data, 
        mulog = mulog, sdlog = sdlog)
    .Call("_mixR_EXlnorm_C", data, mulog, sdlog)
}
