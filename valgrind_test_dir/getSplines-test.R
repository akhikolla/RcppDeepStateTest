function (x, y, id, detail) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getSplines"]][[length(e[["getSplines"]]) + 1]] <- list(x = x, 
        y = y, id = id, detail = detail)
    .Call("_hierarchicalSets_getSplines", PACKAGE = "hierarchicalSets", 
        x, y, id, detail)
}
