function (parent, order, weight, height) 
{
    e <- get("data.env", .GlobalEnv)
    e[["partitionTree"]][[length(e[["partitionTree"]]) + 1]] <- list(parent = parent, 
        order = order, weight = weight, height = height)
    .Call("_ggraph_partitionTree", PACKAGE = "ggraph", parent, 
        order, weight, height)
}
