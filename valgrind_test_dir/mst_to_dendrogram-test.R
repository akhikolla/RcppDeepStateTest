function (mst) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mst_to_dendrogram"]][[length(e[["mst_to_dendrogram"]]) + 
        1]] <- list(mst = mst)
    .Call("_dbscan_mst_to_dendrogram", mst)
}
