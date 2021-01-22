function (y, W, D, Z, tseq, iter, tol) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stress_focus"]][[length(e[["stress_focus"]]) + 1]] <- list(y = y, 
        W = W, D = D, Z = Z, tseq = tseq, iter = iter, tol = tol)
    .Call("_graphlayouts_stress_focus", y, W, D, Z, tseq, iter, 
        tol)
}
