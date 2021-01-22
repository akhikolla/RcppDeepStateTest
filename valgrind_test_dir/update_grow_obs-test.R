function (prior_tree_matrix_temp, grow_node, left_daughter, d, 
    ld_obs, rd_obs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["update_grow_obs"]][[length(e[["update_grow_obs"]]) + 
        1]] <- list(prior_tree_matrix_temp = prior_tree_matrix_temp, 
        grow_node = grow_node, left_daughter = left_daughter, 
        d = d, ld_obs = ld_obs, rd_obs = rd_obs)
    .Call("_bartBMA_update_grow_obs", prior_tree_matrix_temp, 
        grow_node, left_daughter, d, ld_obs, rd_obs)
}
