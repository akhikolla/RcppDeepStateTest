function (treetable) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_internal_nodes"]][[length(e[["find_internal_nodes"]]) + 
        1]] <- list(treetable = treetable)
    .Call("_bartBMA_find_internal_nodes", treetable)
}
