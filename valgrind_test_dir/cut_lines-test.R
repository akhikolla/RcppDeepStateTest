function (x, y, id, start_width, start_height, end_width, end_height, 
    start_type, end_type) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cut_lines"]][[length(e[["cut_lines"]]) + 1]] <- list(x = x, 
        y = y, id = id, start_width = start_width, start_height = start_height, 
        end_width = end_width, end_height = end_height, start_type = start_type, 
        end_type = end_type)
    .Call("_ggraph_cut_lines", PACKAGE = "ggraph", x, y, id, 
        start_width, start_height, end_width, end_height, start_type, 
        end_type)
}
