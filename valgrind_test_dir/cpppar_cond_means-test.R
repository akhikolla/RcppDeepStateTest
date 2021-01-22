function (mat_vars, treat, nthreads = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_cond_means"]][[length(e[["cpppar_cond_means"]]) + 
        1]] <- list(mat_vars = mat_vars, treat = treat, nthreads = nthreads)
    .Call("_fixest_cpppar_cond_means", mat_vars, treat, nthreads)
}
