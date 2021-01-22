function (data, eps, type, bucketSize, splitRule, approx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["frNN_int"]][[length(e[["frNN_int"]]) + 1]] <- list(data = data, 
        eps = eps, type = type, bucketSize = bucketSize, splitRule = splitRule, 
        approx = approx)
    .Call("_dbscan_frNN_int", data, eps, type, bucketSize, splitRule, 
        approx)
}
