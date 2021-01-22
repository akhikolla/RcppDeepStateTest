function (ances) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nTipsFastCpp"]][[length(e[["nTipsFastCpp"]]) + 1]] <- list(ances = ances)
    .Call("_phylobase_nTipsFastCpp", ances)
}
