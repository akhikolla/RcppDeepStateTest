function (sortedValues, valueToSearch) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lbNumeric"]][[length(e[["lbNumeric"]]) + 1]] <- list(sortedValues = sortedValues, 
        valueToSearch = valueToSearch)
    .Call("_bsearchtools_lbNumeric", sortedValues, valueToSearch)
}
