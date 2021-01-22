function (tpr, fpr, param, measure) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_cached_perf"]][[length(e[["get_cached_perf"]]) + 
        1]] <- list(tpr = tpr, fpr = fpr, param = param, measure = measure)
    .Call("_fbroc_get_cached_perf", PACKAGE = "fbroc", tpr, fpr, 
        param, measure)
}
