function (sigma, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitn_skewness"]][[length(e[["splitn_skewness"]]) + 
        1]] <- list(sigma = sigma, lmd = lmd)
    .Call("_dng_splitn_skewness", PACKAGE = "dng", sigma, lmd)
}
