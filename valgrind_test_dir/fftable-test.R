function (df, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fftable"]][[length(e[["fftable"]]) + 1]] <- list(df = df, 
        w = w)
    .Call("_BNSL_fftable", df, w)
}
