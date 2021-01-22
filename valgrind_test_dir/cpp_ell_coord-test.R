function (bound_x, bound_y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_ell_coord"]][[length(e[["cpp_ell_coord"]]) + 1]] <- list(bound_x = bound_x, 
        bound_y = bound_y)
    .Call("_IFC_cpp_ell_coord", bound_x, bound_y)
}
