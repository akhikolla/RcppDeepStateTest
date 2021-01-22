function (cm, data, weight, nclust) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ComputeMeans"]][[length(e[["ComputeMeans"]]) + 1]] <- list(cm = cm, 
        data = data, weight = weight, nclust = nclust)
    .Call("_lsbclust_ComputeMeans", cm, data, weight, nclust)
}
