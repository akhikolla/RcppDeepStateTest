function (ances) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nTipsSafe"]][[length(e[["nTipsSafe"]]) + 1]] <- list(ances = ances)
    .Call("_phylobase_nTipsSafe", ances)
}
