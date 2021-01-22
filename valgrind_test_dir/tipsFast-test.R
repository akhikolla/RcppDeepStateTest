function (ances) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tipsFast"]][[length(e[["tipsFast"]]) + 1]] <- list(ances = ances)
    .Call("_phylobase_tipsFast", ances)
}
