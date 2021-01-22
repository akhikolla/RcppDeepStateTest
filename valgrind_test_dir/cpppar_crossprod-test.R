function (X, w, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_crossprod"]][[length(e[["cpppar_crossprod"]]) + 
        1]] <- list(X = X, w = w, nthreads = nthreads)
    .Call("_fixest_cpppar_crossprod", X, w, nthreads)
}
