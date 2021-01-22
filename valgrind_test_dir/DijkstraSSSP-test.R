function (Adj, Costs, source) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DijkstraSSSP"]][[length(e[["DijkstraSSSP"]]) + 1]] <- list(Adj = Adj, 
        Costs = Costs, source = source)
    .Call("_ProjectionBasedClustering_DijkstraSSSP", PACKAGE = "ProjectionBasedClustering", 
        Adj, Costs, source)
}
