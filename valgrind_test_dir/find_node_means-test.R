function (sum_tree, term_nodes) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_node_means"]][[length(e[["find_node_means"]]) + 
        1]] <- list(sum_tree = sum_tree, term_nodes = term_nodes)
    .Call("_bartBMA_find_node_means", sum_tree, term_nodes)
}
