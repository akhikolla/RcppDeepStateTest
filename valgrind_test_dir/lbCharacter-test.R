function (sortedValues, valueToSearch) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lbCharacter"]][[length(e[["lbCharacter"]]) + 1]] <- list(sortedValues = sortedValues, 
        valueToSearch = valueToSearch)
    .Call("_bsearchtools_lbCharacter", sortedValues, valueToSearch)
}
