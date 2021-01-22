function (pred, true_class, param, n_boot, measure) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_uncached_perf"]][[length(e[["get_uncached_perf"]]) + 
        1]] <- list(pred = pred, true_class = true_class, param = param, 
        n_boot = n_boot, measure = measure)
    .Call("_fbroc_get_uncached_perf", PACKAGE = "fbroc", pred, 
        true_class, param, n_boot, measure)
}
