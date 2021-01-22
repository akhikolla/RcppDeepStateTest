function (prior_tree_table_temp, grow_node) 
{
    e <- get("data.env", .GlobalEnv)
    e[["add_rows"]][[length(e[["add_rows"]]) + 1]] <- list(prior_tree_table_temp = prior_tree_table_temp, 
        grow_node = grow_node)
    .Call("_bartBMA_add_rows", prior_tree_table_temp, grow_node)
}
