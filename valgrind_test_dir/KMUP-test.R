function (X, b, d, xx, e, L, Ve, pi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["KMUP"]][[length(e[["KMUP"]]) + 1]] <- list(X = X, b = b, 
        d = d, xx = xx, e = e, L = L, Ve = Ve, pi = pi)
    .Call("_NAM_KMUP", X, b, d, xx, e, L, Ve, pi)
}
