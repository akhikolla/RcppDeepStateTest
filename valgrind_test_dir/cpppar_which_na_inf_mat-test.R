function (mat, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_which_na_inf_mat"]][[length(e[["cpppar_which_na_inf_mat"]]) + 
        1]] <- list(mat = mat, nthreads = nthreads)
    .Call("_fixest_cpppar_which_na_inf_mat", mat, nthreads)
}
