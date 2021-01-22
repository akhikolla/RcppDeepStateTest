function (dist, n, minPts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["coreFromDist"]][[length(e[["coreFromDist"]]) + 1]] <- list(dist = dist, 
        n = n, minPts = minPts)
    .Call("_dbscan_coreFromDist", dist, n, minPts)
}
