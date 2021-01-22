function (tree_table, tree_matrix, resids, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["update_mean_var"]][[length(e[["update_mean_var"]]) + 
        1]] <- list(tree_table = tree_table, tree_matrix = tree_matrix, 
        resids = resids, a = a)
    .Call("_bartBMA_update_mean_var", tree_table, tree_matrix, 
        resids, a)
}
