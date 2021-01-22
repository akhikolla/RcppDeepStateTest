function (ances) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tabulateTips"]][[length(e[["tabulateTips"]]) + 1]] <- list(ances = ances)
    .Call("_phylobase_tabulateTips", ances)
}
