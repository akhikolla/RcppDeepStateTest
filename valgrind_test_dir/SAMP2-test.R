function (X, g, y, xx, E, L, N, Ve) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SAMP2"]][[length(e[["SAMP2"]]) + 1]] <- list(X = X, g = g, 
        y = y, xx = xx, E = E, L = L, N = N, Ve = Ve)
    invisible(c(".Call", "'_NAM_SAMP2`", "X", "g", "y", "xx", 
    "E", "L", "N", "Ve"))
}
