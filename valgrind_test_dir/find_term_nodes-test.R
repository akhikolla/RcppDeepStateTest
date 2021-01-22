function (tree_table) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_term_nodes"]][[length(e[["find_term_nodes"]]) + 
        1]] <- list(tree_table = tree_table)
    .Call("_bartBMA_find_term_nodes", tree_table)
}
