function (mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_matrix_smooth"]][[length(e[["do_matrix_smooth"]]) + 
        1]] <- list(mat = mat)
    .Call("_oce_do_matrix_smooth", mat)
}
