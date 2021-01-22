function (y, X, cxx, xx, maxit = 50L, tol = 1e-05) 
{
    e <- get("data.env", .GlobalEnv)
    e[["NOR"]][[length(e[["NOR"]]) + 1]] <- list(y = y, X = X, 
        cxx = cxx, xx = xx, maxit = maxit, tol = tol)
    .Call("_NAM_NOR", y, X, cxx, xx, maxit, tol)
}
