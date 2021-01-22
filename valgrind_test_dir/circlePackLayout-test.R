function (parent, weight) 
{
    e <- get("data.env", .GlobalEnv)
    e[["circlePackLayout"]][[length(e[["circlePackLayout"]]) + 
        1]] <- list(parent = parent, weight = weight)
    .Call("_ggraph_circlePackLayout", PACKAGE = "ggraph", parent, 
        weight)
}
