function (parent) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_paths"]][[length(e[["get_paths"]]) + 1]] <- list(parent = parent)
    .Call("_tidygraph_get_paths", PACKAGE = "tidygraph", parent)
}
