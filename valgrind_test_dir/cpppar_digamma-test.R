function (x, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_digamma"]][[length(e[["cpppar_digamma"]]) + 1]] <- list(x = x, 
        nthreads = nthreads)
    .Call("_fixest_cpppar_digamma", x, nthreads)
}
