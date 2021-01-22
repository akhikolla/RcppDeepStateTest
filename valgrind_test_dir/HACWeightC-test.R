function (iLag) 
{
    e <- get("data.env", .GlobalEnv)
    e[["HACWeightC"]][[length(e[["HACWeightC"]]) + 1]] <- list(iLag = iLag)
    .Call("_DriftBurstHypothesis_HACWeightC", iLag)
}
