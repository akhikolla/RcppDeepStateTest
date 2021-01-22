function (ances, desc) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tipsSafe"]][[length(e[["tipsSafe"]]) + 1]] <- list(ances = ances, 
        desc = desc)
    .Call("_phylobase_tipsSafe", ances, desc)
}
