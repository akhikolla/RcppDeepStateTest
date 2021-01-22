function (tree_matrix_temp, terminal_node) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_term_obs_gs"]][[length(e[["find_term_obs_gs"]]) + 
        1]] <- list(tree_matrix_temp = tree_matrix_temp, terminal_node = terminal_node)
    .Call("_bartBMA_find_term_obs_gs", tree_matrix_temp, terminal_node)
}
