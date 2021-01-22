function (n, m, Xmat, yvec, switchIter, numLambda, minLambda, 
    alpha) 
{
    e <- get("data.env", .GlobalEnv)
    e[["clogitl1_c"]][[length(e[["clogitl1_c"]]) + 1]] <- list(n = n, 
        m = m, Xmat = Xmat, yvec = yvec, switchIter = switchIter, 
        numLambda = numLambda, minLambda = minLambda, alpha = alpha)
    .Call("_clogitL1_clogitl1_c", PACKAGE = "clogitL1", n, m, 
        Xmat, yvec, switchIter, numLambda, minLambda, alpha)
}
