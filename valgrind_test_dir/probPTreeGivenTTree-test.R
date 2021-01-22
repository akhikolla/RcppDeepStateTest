function (ctree, neg, w = integer(0)) 
{
    e <- get("data.env", .GlobalEnv)
    e[["probPTreeGivenTTree"]][[length(e[["probPTreeGivenTTree"]]) + 
        1]] <- list(ctree = ctree, neg = neg, w = w)
    .Call("_TransPhylo_probPTreeGivenTTree", PACKAGE = "TransPhylo", 
        ctree, neg, w)
}
