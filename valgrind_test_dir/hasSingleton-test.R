function (ances) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hasSingleton"]][[length(e[["hasSingleton"]]) + 1]] <- list(ances = ances)
    .Call("_phylobase_hasSingleton", ances)
}
