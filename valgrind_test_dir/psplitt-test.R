function (q, mu, df, phi, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["psplitt"]][[length(e[["psplitt"]]) + 1]] <- list(q = q, 
        mu = mu, df = df, phi = phi, lmd = lmd)
    .Call("_dng_psplitt", PACKAGE = "dng", q, mu, df, phi, lmd)
}
