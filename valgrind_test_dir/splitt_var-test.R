function (df, phi, lmd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitt_var"]][[length(e[["splitt_var"]]) + 1]] <- list(df = df, 
        phi = phi, lmd = lmd)
    .Call("_dng_splitt_var", PACKAGE = "dng", df, phi, lmd)
}
