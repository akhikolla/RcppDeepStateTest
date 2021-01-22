function (leaves, nodes, alpha) 
{
    e <- get("data.env", .GlobalEnv)
    e[["coalescent"]][[length(e[["coalescent"]]) + 1]] <- list(leaves = leaves, 
        nodes = nodes, alpha = alpha)
    .Call("_TransPhylo_coalescent", PACKAGE = "TransPhylo", leaves, 
        nodes, alpha)
}
