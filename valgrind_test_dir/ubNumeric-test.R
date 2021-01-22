function (sortedValues, valueToSearch) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ubNumeric"]][[length(e[["ubNumeric"]]) + 1]] <- list(sortedValues = sortedValues, 
        valueToSearch = valueToSearch)
    .Call("_bsearchtools_ubNumeric", sortedValues, valueToSearch)
}
