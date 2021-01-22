function (n, mu, sigma, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rsplitn"]][[length(e[["rsplitn"]]) + 1]] <- list(n = n, 
        mu = mu, sigma = sigma, lmd = lmd)
    .Call("_dng_rsplitn", PACKAGE = "dng", n, mu, sigma, lmd)
}
