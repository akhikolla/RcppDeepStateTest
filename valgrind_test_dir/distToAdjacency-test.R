function (constraints, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["distToAdjacency"]][[length(e[["distToAdjacency"]]) + 
        1]] <- list(constraints = constraints, N = N)
    .Call("_dbscan_distToAdjacency", constraints, N)
}
