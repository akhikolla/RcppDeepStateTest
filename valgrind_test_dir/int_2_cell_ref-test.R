function (cols) 
{
    e <- get("data.env", .GlobalEnv)
    e[["int_2_cell_ref"]][[length(e[["int_2_cell_ref"]]) + 1]] <- list(cols = cols)
    .Call("_openxlsx_int_2_cell_ref", cols)
}
