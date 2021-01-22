function (mu, sigma, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitn_mean"]][[length(e[["splitn_mean"]]) + 1]] <- list(mu = mu, 
        sigma = sigma, lmd = lmd)
    .Call("_dng_splitn_mean", PACKAGE = "dng", mu, sigma, lmd)
}
