function (y_var, window_size = 15L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_indices"]][[length(e[["get_indices"]]) + 1]] <- list(y_var = y_var, 
        window_size = window_size)
    .Call("_PAutilities_get_indices", y_var, window_size)
}
