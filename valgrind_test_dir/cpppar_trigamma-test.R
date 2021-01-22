function (x, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_trigamma"]][[length(e[["cpppar_trigamma"]]) + 
        1]] <- list(x = x, nthreads = nthreads)
    .Call("_fixest_cpppar_trigamma", x, nthreads)
}
