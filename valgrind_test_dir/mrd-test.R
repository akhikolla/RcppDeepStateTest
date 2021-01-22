function (dm, cd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mrd"]][[length(e[["mrd"]]) + 1]] <- list(dm = dm, cd = cd)
    .Call("_dbscan_mrd", dm, cd)
}
