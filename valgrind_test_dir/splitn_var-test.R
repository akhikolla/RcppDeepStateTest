function (sigma, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitn_var"]][[length(e[["splitn_var"]]) + 1]] <- list(sigma = sigma, 
        lmd = lmd)
    .Call("_dng_splitn_var", PACKAGE = "dng", sigma, lmd)
}
