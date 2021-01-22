function (Data, pData, NeighborhoodSize = 20L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_klmeasure"]][[length(e[["c_klmeasure"]]) + 1]] <- list(Data = Data, 
        pData = pData, NeighborhoodSize = NeighborhoodSize)
    .Call("_ProjectionBasedClustering_c_klmeasure", PACKAGE = "ProjectionBasedClustering", 
        Data, pData, NeighborhoodSize)
}
