function (x, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_exp"]][[length(e[["cpppar_exp"]]) + 1]] <- list(x = x, 
        nthreads = nthreads)
    .Call("_fixest_cpppar_exp", x, nthreads)
}
