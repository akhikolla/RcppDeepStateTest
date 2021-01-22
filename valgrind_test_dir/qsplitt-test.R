function (p, mu, df, phi, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["qsplitt"]][[length(e[["qsplitt"]]) + 1]] <- list(p = p, 
        mu = mu, df = df, phi = phi, lmd = lmd)
    .Call("_dng_qsplitt", PACKAGE = "dng", p, mu, df, phi, lmd)
}
