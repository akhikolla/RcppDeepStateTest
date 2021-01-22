function (tree_table, tree_matrix, new_mean, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["update_predictions"]][[length(e[["update_predictions"]]) + 
        1]] <- list(tree_table = tree_table, tree_matrix = tree_matrix, 
        new_mean = new_mean, n = n)
    .Call("_bartBMA_update_predictions", tree_table, tree_matrix, 
        new_mean, n)
}
