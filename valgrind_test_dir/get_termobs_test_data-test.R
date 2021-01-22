function (test_data, tree_data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_termobs_test_data"]][[length(e[["get_termobs_test_data"]]) + 
        1]] <- list(test_data = test_data, tree_data = tree_data)
    .Call("_bartBMA_get_termobs_test_data", test_data, tree_data)
}
