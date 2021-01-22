function (n, ex, tx, tol = 1e-04, max_iter = 100L, xleft = 0.1, 
    xright = 5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gamma_bisection_C"]][[length(e[["gamma_bisection_C"]]) + 
        1]] <- list(n = n, ex = ex, tx = tx, tol = tol, max_iter = max_iter, 
        xleft = xleft, xright = xright)
    .Call("_mixR_gamma_bisection_C", n, ex, tx, tol, max_iter, 
        xleft, xright)
}
