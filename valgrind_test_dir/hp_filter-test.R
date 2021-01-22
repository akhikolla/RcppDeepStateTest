function (x, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hp_filter"]][[length(e[["hp_filter"]]) + 1]] <- list(x = x, 
        lambda = lambda)
    .Call("_lpirfs_hp_filter", x, lambda)
}
