function (prior_tree_matrix_temp, left_daughter, d, ld_obs, rd_obs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_obs_to_update_grow"]][[length(e[["find_obs_to_update_grow"]]) + 
        1]] <- list(prior_tree_matrix_temp = prior_tree_matrix_temp, 
        left_daughter = left_daughter, d = d, ld_obs = ld_obs, 
        rd_obs = rd_obs)
    .Call("_bartBMA_find_obs_to_update_grow", prior_tree_matrix_temp, 
        left_daughter, d, ld_obs, rd_obs)
}
