function (X, Use, b, d, xx, E, L, Ve, pi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["KMUP2"]][[length(e[["KMUP2"]]) + 1]] <- list(X = X, Use = Use, 
        b = b, d = d, xx = xx, E = E, L = L, Ve = Ve, pi = pi)
    .Call("_NAM_KMUP2", X, Use, b, d, xx, E, L, Ve, pi)
}
