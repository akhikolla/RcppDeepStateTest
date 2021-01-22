function (data, weight, M, nclust) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AssignCluster"]][[length(e[["AssignCluster"]]) + 1]] <- list(data = data, 
        weight = weight, M = M, nclust = nclust)
    .Call("_lsbclust_AssignCluster", data, weight, M, nclust)
}
