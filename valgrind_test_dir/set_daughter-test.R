function (left_daughter, right_daughter, ld_obs, rd_obs, tree_matrix_temp, 
    term_cols) 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_daughter"]][[length(e[["set_daughter"]]) + 1]] <- list(left_daughter = left_daughter, 
        right_daughter = right_daughter, ld_obs = ld_obs, rd_obs = rd_obs, 
        tree_matrix_temp = tree_matrix_temp, term_cols = term_cols)
    .Call("_bartBMA_set_daughter", left_daughter, right_daughter, 
        ld_obs, rd_obs, tree_matrix_temp, term_cols)
}
