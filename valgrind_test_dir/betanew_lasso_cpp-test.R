function (xx, xy, beta, M, y, Lambda1, Lambda2, iter, tol) 
{
    e <- get("data.env", .GlobalEnv)
    e[["betanew_lasso_cpp"]][[length(e[["betanew_lasso_cpp"]]) + 
        1]] <- list(xx = xx, xy = xy, beta = beta, M = M, y = y, 
        Lambda1 = Lambda1, Lambda2 = Lambda2, iter = iter, tol = tol)
    .Call("_LassoNet_betanew_lasso_cpp", PACKAGE = "LassoNet", 
        xx, xy, beta, M, y, Lambda1, Lambda2, iter, tol)
}
