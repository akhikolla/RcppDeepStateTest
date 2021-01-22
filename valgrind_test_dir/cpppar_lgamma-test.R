function (x, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_lgamma"]][[length(e[["cpppar_lgamma"]]) + 1]] <- list(x = x, 
        nthreads = nthreads)
    .Call("_fixest_cpppar_lgamma", x, nthreads)
}
