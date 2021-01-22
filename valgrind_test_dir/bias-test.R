function (dvs, nd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bias"]][[length(e[["bias"]]) + 1]] <- list(dvs = dvs, 
        nd = nd)
    .Call("_redist_bias", dvs, nd)
}
