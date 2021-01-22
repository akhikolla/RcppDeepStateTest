function (levels, values) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binary_representation"]][[length(e[["binary_representation"]]) + 
        1]] <- list(levels = levels, values = values)
    .Call("_simPop_binary_representation", PACKAGE = "simPop", 
        levels, values)
}
