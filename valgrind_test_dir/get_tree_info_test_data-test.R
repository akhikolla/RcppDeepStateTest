function (test_data, tree_data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_tree_info_test_data"]][[length(e[["get_tree_info_test_data"]]) + 
        1]] <- list(test_data = test_data, tree_data = tree_data)
    .Call("_bartBMA_get_tree_info_test_data", test_data, tree_data)
}
