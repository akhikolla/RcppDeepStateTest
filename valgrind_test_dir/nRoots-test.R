function (ances) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nRoots"]][[length(e[["nRoots"]]) + 1]] <- list(ances = ances)
    .Call("_phylobase_nRoots", ances)
}
