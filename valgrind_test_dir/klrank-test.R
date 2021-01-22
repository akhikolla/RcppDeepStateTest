function (Data, pData, NeighborhoodSize = 20L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["klrank"]][[length(e[["klrank"]]) + 1]] <- list(Data = Data, 
        pData = pData, NeighborhoodSize = NeighborhoodSize)
    .Call("_ProjectionBasedClustering_klrank", PACKAGE = "ProjectionBasedClustering", 
        Data, pData, NeighborhoodSize)
}
