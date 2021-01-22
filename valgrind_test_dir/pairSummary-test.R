function (P, I, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pairSummary"]][[length(e[["pairSummary"]]) + 1]] <- list(P = P, 
        I = I, order = order)
    .Call("_hierarchicalSets_pairSummary", PACKAGE = "hierarchicalSets", 
        P, I, order)
}
