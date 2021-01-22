function (x_dist, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["prims"]][[length(e[["prims"]]) + 1]] <- list(x_dist = x_dist, 
        n = n)
    .Call("_dbscan_prims", x_dist, n)
}
