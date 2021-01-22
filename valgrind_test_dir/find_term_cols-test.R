function (tree_matrix_temp, terminal_node) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_term_cols"]][[length(e[["find_term_cols"]]) + 1]] <- list(tree_matrix_temp = tree_matrix_temp, 
        terminal_node = terminal_node)
    .Call("_bartBMA_find_term_cols", tree_matrix_temp, terminal_node)
}
