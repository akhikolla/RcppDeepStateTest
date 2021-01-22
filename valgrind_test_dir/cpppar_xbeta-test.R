function (X, beta, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_xbeta"]][[length(e[["cpppar_xbeta"]]) + 1]] <- list(X = X, 
        beta = beta, nthreads = nthreads)
    .Call("_fixest_cpppar_xbeta", X, beta, nthreads)
}
