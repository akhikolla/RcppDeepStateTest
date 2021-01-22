function (x, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_poisson_linkinv"]][[length(e[["cpppar_poisson_linkinv"]]) + 
        1]] <- list(x = x, nthreads = nthreads)
    .Call("_fixest_cpppar_poisson_linkinv", x, nthreads)
}
