function (y, W, D, iter, tol) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stress_major"]][[length(e[["stress_major"]]) + 1]] <- list(y = y, 
        W = W, D = D, iter = iter, tol = tol)
    .Call("_graphlayouts_stress_major", y, W, D, iter, tol)
}
