function (t) 
{
    e <- get("data.env", .GlobalEnv)
    e[["map_cell_types_to_char"]][[length(e[["map_cell_types_to_char"]]) + 
        1]] <- list(t = t)
    .Call("_openxlsx_map_cell_types_to_char", t)
}
