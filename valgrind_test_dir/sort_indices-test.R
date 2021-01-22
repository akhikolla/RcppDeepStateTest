function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sort_indices"]][[length(e[["sort_indices"]]) + 1]] <- list(x = x)
    .Call("_tidygenomics_sort_indices", x)
}
