function (starts, ends, max_distance = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cluster_interval"]][[length(e[["cluster_interval"]]) + 
        1]] <- list(starts = starts, ends = ends, max_distance = max_distance)
    .Call("_tidygenomics_cluster_interval", starts, ends, max_distance)
}
