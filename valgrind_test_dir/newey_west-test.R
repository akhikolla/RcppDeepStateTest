function (y, x, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["newey_west"]][[length(e[["newey_west"]]) + 1]] <- list(y = y, 
        x = x, h = h)
    .Call("_lpirfs_newey_west", y, x, h)
}
