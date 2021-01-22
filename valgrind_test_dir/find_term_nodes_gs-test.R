function (tree_table) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_term_nodes_gs"]][[length(e[["find_term_nodes_gs"]]) + 
        1]] <- list(tree_table = tree_table)
    .Call("_bartBMA_find_term_nodes_gs", tree_table)
}
