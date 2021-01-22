function (t) 
{
    e <- get("data.env", .GlobalEnv)
    e[["map_cell_types_to_integer"]][[length(e[["map_cell_types_to_integer"]]) + 
        1]] <- list(t = t)
    .Call("_openxlsx_map_cell_types_to_integer", t)
}
