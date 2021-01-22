function (sortedValues, valueToSearch) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ubInteger"]][[length(e[["ubInteger"]]) + 1]] <- list(sortedValues = sortedValues, 
        valueToSearch = valueToSearch)
    .Call("_bsearchtools_ubInteger", sortedValues, valueToSearch)
}
