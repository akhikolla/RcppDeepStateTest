function (dvs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["meanmedian"]][[length(e[["meanmedian"]]) + 1]] <- list(dvs = dvs)
    .Call("_redist_meanmedian", dvs)
}
