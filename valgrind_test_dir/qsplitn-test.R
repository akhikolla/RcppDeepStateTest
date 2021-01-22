function (p, mu, sigma, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["qsplitn"]][[length(e[["qsplitn"]]) + 1]] <- list(p = p, 
        mu = mu, sigma = sigma, lmd = lmd)
    .Call("_dng_qsplitn", PACKAGE = "dng", p, mu, sigma, lmd)
}
