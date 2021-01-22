function (data, clusters) 
{
    e <- get("data.env", .GlobalEnv)
    e[["clusterCor_c"]][[length(e[["clusterCor_c"]]) + 1]] <- list(data = data, 
        clusters = clusters)
    .Call("_segmenTier_clusterCor_c", PACKAGE = "segmenTier", 
        data, clusters)
}
