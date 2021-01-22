function (X, y, w, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_xwy"]][[length(e[["cpppar_xwy"]]) + 1]] <- list(X = X, 
        y = y, w = w, nthreads = nthreads)
    .Call("_fixest_cpppar_xwy", X, y, w, nthreads)
}
