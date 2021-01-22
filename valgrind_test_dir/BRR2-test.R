function (y, X1, X2, it = 1500, bi = 500, df = 5, R2 = 0.5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["BRR2"]][[length(e[["BRR2"]]) + 1]] <- list(y = y, X1 = X1, 
        X2 = X2, it = it, bi = bi, df = df, R2 = R2)
    .Call("_NAM_BRR2", y, X1, X2, it, bi, df, R2)
}
