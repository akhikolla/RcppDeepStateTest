function (label) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hasDuplicatedLabelsCpp"]][[length(e[["hasDuplicatedLabelsCpp"]]) + 
        1]] <- list(label = label)
    .Call("_phylobase_hasDuplicatedLabelsCpp", label)
}
