function (nclust, start, data, weight, eps = 1e-08, IterMax = 100L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["KMeansW"]][[length(e[["KMeansW"]]) + 1]] <- list(nclust = nclust, 
        start = start, data = data, weight = weight, eps = eps, 
        IterMax = IterMax)
    .Call("_lsbclust_KMeansW", nclust, start, data, weight, eps, 
        IterMax)
}
