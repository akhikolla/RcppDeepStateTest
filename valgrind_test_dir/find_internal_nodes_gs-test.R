function (treetable) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_internal_nodes_gs"]][[length(e[["find_internal_nodes_gs"]]) + 
        1]] <- list(treetable = treetable)
    .Call("_bartBMA_find_internal_nodes_gs", treetable)
}
