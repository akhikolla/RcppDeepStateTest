function (data, k, type, bucketSize, splitRule, approx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["kNN_int"]][[length(e[["kNN_int"]]) + 1]] <- list(data = data, 
        k = k, type = type, bucketSize = bucketSize, splitRule = splitRule, 
        approx = approx)
    .Call("_dbscan_kNN_int", data, k, type, bucketSize, splitRule, 
        approx)
}
