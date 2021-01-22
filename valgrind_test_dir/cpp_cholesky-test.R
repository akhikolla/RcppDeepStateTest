function (X, tol = 1/1e+05/1e+05, nthreads = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_cholesky"]][[length(e[["cpp_cholesky"]]) + 1]] <- list(X = X, 
        tol = tol, nthreads = nthreads)
    .Call("_fixest_cpp_cholesky", X, tol, nthreads)
}
