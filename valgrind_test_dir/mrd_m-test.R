function (dm, cd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mrd_m"]][[length(e[["mrd_m"]]) + 1]] <- list(dm = dm, 
        cd = cd)
    .Call("_dbscan_mrd_m", dm, cd)
}
