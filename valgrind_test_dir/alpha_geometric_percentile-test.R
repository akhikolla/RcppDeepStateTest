function (dat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alpha_geometric_percentile"]][[length(e[["alpha_geometric_percentile"]]) + 
        1]] <- list(dat = dat)
    .Call("_ptsuite_alpha_geometric_percentile", PACKAGE = "ptsuite", 
        dat)
}
