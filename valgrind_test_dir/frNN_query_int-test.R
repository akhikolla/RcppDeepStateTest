function (data, query, eps, type, bucketSize, splitRule, approx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["frNN_query_int"]][[length(e[["frNN_query_int"]]) + 1]] <- list(data = data, 
        query = query, eps = eps, type = type, bucketSize = bucketSize, 
        splitRule = splitRule, approx = approx)
    .Call("_dbscan_frNN_query_int", data, query, eps, type, bucketSize, 
        splitRule, approx)
}
