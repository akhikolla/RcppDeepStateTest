function (y, X, it = 3000, bi = 500, df = 5, R2 = 0.5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["BCpi"]][[length(e[["BCpi"]]) + 1]] <- list(y = y, X = X, 
        it = it, bi = bi, df = df, R2 = R2)
    .Call("_NAM_BCpi", y, X, it, bi, df, R2)
}
