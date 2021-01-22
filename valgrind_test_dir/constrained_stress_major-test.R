function (y, dim, W, D, iter, tol) 
{
    e <- get("data.env", .GlobalEnv)
    e[["constrained_stress_major"]][[length(e[["constrained_stress_major"]]) + 
        1]] <- list(y = y, dim = dim, W = W, D = D, iter = iter, 
        tol = tol)
    .Call("_graphlayouts_constrained_stress_major", y, dim, W, 
        D, iter, tol)
}
