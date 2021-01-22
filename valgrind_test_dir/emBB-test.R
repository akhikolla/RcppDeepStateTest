function (y, gen, df = 10, R2 = 0.5, Pi = 0.75) 
{
    e <- get("data.env", .GlobalEnv)
    e[["emBB"]][[length(e[["emBB"]]) + 1]] <- list(y = y, gen = gen, 
        df = df, R2 = R2, Pi = Pi)
    .Call("_NAM_emBB", y, gen, df, R2, Pi)
}
