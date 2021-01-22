function (data, eps, type, bucketSize, splitRule, approx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dbscan_density_int"]][[length(e[["dbscan_density_int"]]) + 
        1]] <- list(data = data, eps = eps, type = type, bucketSize = bucketSize, 
        splitRule = splitRule, approx = approx)
    .Call("_dbscan_dbscan_density_int", data, eps, type, bucketSize, 
        splitRule, approx)
}
