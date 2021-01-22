function (N, S, r, min_its, max_its, signif, log_dismiss) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gset_raw"]][[length(e[["gset_raw"]]) + 1]] <- list(N = N, 
        S = S, r = r, min_its = min_its, max_its = max_its, signif = signif, 
        log_dismiss = log_dismiss)
    .Call("_gsEasy_gset_raw", PACKAGE = "gsEasy", N, S, r, min_its, 
        max_its, signif, log_dismiss)
}
