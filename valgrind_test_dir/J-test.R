function (obs_to_nodes_temp, tree_term_nodes) 
{
    e <- get("data.env", .GlobalEnv)
    e[["J"]][[length(e[["J"]]) + 1]] <- list(obs_to_nodes_temp = obs_to_nodes_temp, 
        tree_term_nodes = tree_term_nodes)
    .Call("_bartBMA_J", obs_to_nodes_temp, tree_term_nodes)
}
