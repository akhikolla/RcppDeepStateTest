function (input_data, depth) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ML"]][[length(e[["ML"]]) + 1]] <- list(input_data = input_data, 
        depth = depth)
    .Call("_BCT_ML", input_data, depth)
}
