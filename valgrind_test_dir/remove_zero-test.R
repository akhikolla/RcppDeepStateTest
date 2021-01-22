function (nodes_at_depth) 
{
    e <- get("data.env", .GlobalEnv)
    e[["remove_zero"]][[length(e[["remove_zero"]]) + 1]] <- list(nodes_at_depth = nodes_at_depth)
    .Call("_bartBMA_remove_zero", nodes_at_depth)
}
