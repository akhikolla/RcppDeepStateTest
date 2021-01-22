function (df, phi, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitt_kurtosis"]][[length(e[["splitt_kurtosis"]]) + 
        1]] <- list(df = df, phi = phi, lmd = lmd)
    .Call("_dng_splitt_kurtosis", PACKAGE = "dng", df, phi, lmd)
}
