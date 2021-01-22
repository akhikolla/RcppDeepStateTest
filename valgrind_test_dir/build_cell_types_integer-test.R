function (classes, n_rows) 
{
    e <- get("data.env", .GlobalEnv)
    e[["build_cell_types_integer"]][[length(e[["build_cell_types_integer"]]) + 
        1]] <- list(classes = classes, n_rows = n_rows)
    .Call("_openxlsx_build_cell_types_integer", classes, n_rows)
}
