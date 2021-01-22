function (sortedValues, valueToSearch) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lbInteger"]][[length(e[["lbInteger"]]) + 1]] <- list(sortedValues = sortedValues, 
        valueToSearch = valueToSearch)
    .Call("_bsearchtools_lbInteger", sortedValues, valueToSearch)
}
