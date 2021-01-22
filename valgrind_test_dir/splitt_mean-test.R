function (mu, df, phi, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitt_mean"]][[length(e[["splitt_mean"]]) + 1]] <- list(mu = mu, 
        df = df, phi = phi, lmd = lmd)
    .Call("_dng_splitt_mean", PACKAGE = "dng", mu, df, phi, lmd)
}
