function (split_vars, num_col, current_vars) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_imp_vars"]][[length(e[["get_imp_vars"]]) + 1]] <- list(split_vars = split_vars, 
        num_col = num_col, current_vars = current_vars)
    .Call("_bartBMA_get_imp_vars", split_vars, num_col, current_vars)
}
