function (nodes_at_depth, grow_node) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_gnp"]][[length(e[["get_gnp"]]) + 1]] <- list(nodes_at_depth = nodes_at_depth, 
        grow_node = grow_node)
    .Call("_bartBMA_get_gnp", nodes_at_depth, grow_node)
}
