function (y, gen, df = 10, R2 = 0.5, Pi = 0.75) 
{
    e <- get("data.env", .GlobalEnv)
    e[["emBC"]][[length(e[["emBC"]]) + 1]] <- list(y = y, gen = gen, 
        df = df, R2 = R2, Pi = Pi)
    .Call("_NAM_emBC", y, gen, df, R2, Pi)
}
