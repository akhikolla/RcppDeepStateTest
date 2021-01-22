function (x, y, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_matprod"]][[length(e[["cpppar_matprod"]]) + 1]] <- list(x = x, 
        y = y, nthreads = nthreads)
    .Call("_fixest_cpppar_matprod", x, y, nthreads)
}
