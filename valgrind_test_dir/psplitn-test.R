function (q, mu, sigma, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["psplitn"]][[length(e[["psplitn"]]) + 1]] <- list(q = q, 
        mu = mu, sigma = sigma, lmd = lmd)
    .Call("_dng_psplitn", PACKAGE = "dng", q, mu, sigma, lmd)
}
