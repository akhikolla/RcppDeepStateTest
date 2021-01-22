function (dat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alpha_percentile"]][[length(e[["alpha_percentile"]]) + 
        1]] <- list(dat = dat)
    .Call("_ptsuite_alpha_percentile", PACKAGE = "ptsuite", dat)
}
