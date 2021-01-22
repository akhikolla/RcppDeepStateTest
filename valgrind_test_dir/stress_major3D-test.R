function (y, W, D, iter, tol) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stress_major3D"]][[length(e[["stress_major3D"]]) + 1]] <- list(y = y, 
        W = W, D = D, iter = iter, tol = tol)
    .Call("_graphlayouts_stress_major3D", y, W, D, iter, tol)
}
