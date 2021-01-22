function (test_data, tree_data, term_node_means) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bartBMA_get_testdata_term_obs_pred"]][[length(e[["bartBMA_get_testdata_term_obs_pred"]]) + 
        1]] <- list(test_data = test_data, tree_data = tree_data, 
        term_node_means = term_node_means)
    .Call("_bartBMA_bartBMA_get_testdata_term_obs_pred", test_data, 
        tree_data, term_node_means)
}
