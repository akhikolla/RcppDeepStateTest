function (x, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_log"]][[length(e[["cpppar_log"]]) + 1]] <- list(x = x, 
        nthreads = nthreads)
    .Call("_fixest_cpppar_log", x, nthreads)
}
