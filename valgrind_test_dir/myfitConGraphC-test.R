function (amat, S, n, tol = 1e-06) 
{
    e <- get("data.env", .GlobalEnv)
    e[["myfitConGraphC"]][[length(e[["myfitConGraphC"]]) + 1]] <- list(amat = amat, 
        S = S, n = n, tol = tol)
    .Call("_robFitConGraph_myfitConGraphC", amat, S, n, tol)
}
