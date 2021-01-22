function (tab, rate) 
{
    e <- get("data.env", .GlobalEnv)
    e[["probSubtree"]][[length(e[["probSubtree"]]) + 1]] <- list(tab = tab, 
        rate = rate)
    .Call("_TransPhylo_probSubtree", PACKAGE = "TransPhylo", 
        tab, rate)
}
