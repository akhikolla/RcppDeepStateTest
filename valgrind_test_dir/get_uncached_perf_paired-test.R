function (pred1, pred2, true_class, param, n_boot, measure) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_uncached_perf_paired"]][[length(e[["get_uncached_perf_paired"]]) + 
        1]] <- list(pred1 = pred1, pred2 = pred2, true_class = true_class, 
        param = param, n_boot = n_boot, measure = measure)
    .Call("_fbroc_get_uncached_perf_paired", PACKAGE = "fbroc", 
        pred1, pred2, true_class, param, n_boot, measure)
}
