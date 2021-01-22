function (dvs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dseatsDVS"]][[length(e[["dseatsDVS"]]) + 1]] <- list(dvs = dvs)
    .Call("_redist_dseatsDVS", dvs)
}
