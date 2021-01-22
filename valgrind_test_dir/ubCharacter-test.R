function (sortedValues, valueToSearch) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ubCharacter"]][[length(e[["ubCharacter"]]) + 1]] <- list(sortedValues = sortedValues, 
        valueToSearch = valueToSearch)
    .Call("_bsearchtools_ubCharacter", sortedValues, valueToSearch)
}
