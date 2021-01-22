function (n, mu, df, phi, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rsplitt"]][[length(e[["rsplitt"]]) + 1]] <- list(n = n, 
        mu = mu, df = df, phi = phi, lmd = lmd)
    .Call("_dng_rsplitt", PACKAGE = "dng", n, mu, df, phi, lmd)
}
