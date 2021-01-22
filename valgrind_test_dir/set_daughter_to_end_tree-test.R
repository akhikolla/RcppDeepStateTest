function (grow_node, prior_tree_table_temp, left_daughter) 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_daughter_to_end_tree"]][[length(e[["set_daughter_to_end_tree"]]) + 
        1]] <- list(grow_node = grow_node, prior_tree_table_temp = prior_tree_table_temp, 
        left_daughter = left_daughter)
    .Call("_bartBMA_set_daughter_to_end_tree", grow_node, prior_tree_table_temp, 
        left_daughter)
}
