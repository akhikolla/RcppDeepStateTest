function (mst, o) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hclustMergeOrder"]][[length(e[["hclustMergeOrder"]]) + 
        1]] <- list(mst = mst, o = o)
    .Call("_dbscan_hclustMergeOrder", mst, o)
}
