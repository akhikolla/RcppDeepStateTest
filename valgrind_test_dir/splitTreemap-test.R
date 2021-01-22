function (parent, order, weight, width, height) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitTreemap"]][[length(e[["splitTreemap"]]) + 1]] <- list(parent = parent, 
        order = order, weight = weight, width = width, height = height)
    .Call("_ggraph_splitTreemap", PACKAGE = "ggraph", parent, 
        order, weight, width, height)
}
