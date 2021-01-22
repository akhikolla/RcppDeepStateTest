function (nclust, start, data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ClustMeans"]][[length(e[["ClustMeans"]]) + 1]] <- list(nclust = nclust, 
        start = start, data = data)
    .Call("_lsbclust_ClustMeans", nclust, start, data)
}
