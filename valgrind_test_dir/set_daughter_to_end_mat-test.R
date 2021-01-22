function (d, prior_tree_matrix_temp, left_daughter, ld_obs, rd_obs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_daughter_to_end_mat"]][[length(e[["set_daughter_to_end_mat"]]) + 
        1]] <- list(d = d, prior_tree_matrix_temp = prior_tree_matrix_temp, 
        left_daughter = left_daughter, ld_obs = ld_obs, rd_obs = rd_obs)
    .Call("_bartBMA_set_daughter_to_end_mat", d, prior_tree_matrix_temp, 
        left_daughter, ld_obs, rd_obs)
}
