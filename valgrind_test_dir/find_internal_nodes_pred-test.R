function (treetable) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_internal_nodes_pred"]][[length(e[["find_internal_nodes_pred"]]) + 
        1]] <- list(treetable = treetable)
    .Call("_bartBMA_find_internal_nodes_pred", treetable)
}
