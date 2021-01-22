function (x_mat, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_check_only_0"]][[length(e[["cpppar_check_only_0"]]) + 
        1]] <- list(x_mat = x_mat, nthreads = nthreads)
    .Call("_fixest_cpppar_check_only_0", x_mat, nthreads)
}
