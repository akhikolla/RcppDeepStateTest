function (df, phi, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitt_skewness"]][[length(e[["splitt_skewness"]]) + 
        1]] <- list(df = df, phi = phi, lmd = lmd)
    .Call("_dng_splitt_skewness", PACKAGE = "dng", df, phi, lmd)
}
