function (P, I, setNames, threshold) 
{
    e <- get("data.env", .GlobalEnv)
    e[["setClustering"]][[length(e[["setClustering"]]) + 1]] <- list(P = P, 
        I = I, setNames = setNames, threshold = threshold)
    .Call("_hierarchicalSets_setClustering", PACKAGE = "hierarchicalSets", 
        P, I, setNames, threshold)
}
