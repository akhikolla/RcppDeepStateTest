function (tpr1, fpr1, tpr2, fpr2, param, measure) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_cached_perf_paired"]][[length(e[["get_cached_perf_paired"]]) + 
        1]] <- list(tpr1 = tpr1, fpr1 = fpr1, tpr2 = tpr2, fpr2 = fpr2, 
        param = param, measure = measure)
    .Call("_fbroc_get_cached_perf_paired", PACKAGE = "fbroc", 
        tpr1, fpr1, tpr2, fpr2, param, measure)
}
