function (test_data, tree_data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_testdata_term_obs"]][[length(e[["get_testdata_term_obs"]]) + 
        1]] <- list(test_data = test_data, tree_data = tree_data)
    .Call("_bartBMA_get_testdata_term_obs", test_data, tree_data)
}
