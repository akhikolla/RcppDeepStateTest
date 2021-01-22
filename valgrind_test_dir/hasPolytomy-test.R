function (ances) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hasPolytomy"]][[length(e[["hasPolytomy"]]) + 1]] <- list(ances = ances)
    .Call("_phylobase_hasPolytomy", ances)
}
