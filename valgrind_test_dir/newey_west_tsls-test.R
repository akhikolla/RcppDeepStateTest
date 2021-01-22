function (y, x, z, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["newey_west_tsls"]][[length(e[["newey_west_tsls"]]) + 
        1]] <- list(y = y, x = x, z = z, h = h)
    .Call("_lpirfs_newey_west_tsls", y, x, z, h)
}
