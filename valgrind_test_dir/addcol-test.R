function (prior_tree_matrix_temp, grow_node, ld_obs, rd_obs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["addcol"]][[length(e[["addcol"]]) + 1]] <- list(prior_tree_matrix_temp = prior_tree_matrix_temp, 
        grow_node = grow_node, ld_obs = ld_obs, rd_obs = rd_obs)
    .Call("_bartBMA_addcol", prior_tree_matrix_temp, grow_node, 
        ld_obs, rd_obs)
}
