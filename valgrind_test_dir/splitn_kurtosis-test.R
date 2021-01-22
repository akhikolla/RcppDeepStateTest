function (lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitn_kurtosis"]][[length(e[["splitn_kurtosis"]]) + 
        1]] <- list(lmd = lmd)
    .Call("_dng_splitn_kurtosis", PACKAGE = "dng", lmd)
}
