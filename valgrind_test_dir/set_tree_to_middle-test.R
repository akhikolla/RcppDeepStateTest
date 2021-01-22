function (node_to_update, prior_tree_table_temp, grow_node, left_daughter) 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_tree_to_middle"]][[length(e[["set_tree_to_middle"]]) + 
        1]] <- list(node_to_update = node_to_update, prior_tree_table_temp = prior_tree_table_temp, 
        grow_node = grow_node, left_daughter = left_daughter)
    .Call("_bartBMA_set_tree_to_middle", node_to_update, prior_tree_table_temp, 
        grow_node, left_daughter)
}
