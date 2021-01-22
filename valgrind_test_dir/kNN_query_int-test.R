function (data, query, k, type, bucketSize, splitRule, approx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["kNN_query_int"]][[length(e[["kNN_query_int"]]) + 1]] <- list(data = data, 
        query = query, k = k, type = type, bucketSize = bucketSize, 
        splitRule = splitRule, approx = approx)
    .Call("_dbscan_kNN_query_int", data, query, k, type, bucketSize, 
        splitRule, approx)
}
