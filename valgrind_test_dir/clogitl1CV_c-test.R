function (n, m, Xmat, yvec, lambdas, keepvec, alpha) 
{
    e <- get("data.env", .GlobalEnv)
    e[["clogitl1CV_c"]][[length(e[["clogitl1CV_c"]]) + 1]] <- list(n = n, 
        m = m, Xmat = Xmat, yvec = yvec, lambdas = lambdas, keepvec = keepvec, 
        alpha = alpha)
    .Call("_clogitL1_clogitl1CV_c", PACKAGE = "clogitL1", n, 
        m, Xmat, yvec, lambdas, keepvec, alpha)
}
