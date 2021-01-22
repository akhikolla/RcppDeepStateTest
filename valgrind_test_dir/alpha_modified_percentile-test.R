function (dat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alpha_modified_percentile"]][[length(e[["alpha_modified_percentile"]]) + 
        1]] <- list(dat = dat)
    .Call("_ptsuite_alpha_modified_percentile", PACKAGE = "ptsuite", 
        dat)
}
