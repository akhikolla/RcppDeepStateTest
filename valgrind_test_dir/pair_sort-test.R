function (i, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pair_sort"]][[length(e[["pair_sort"]]) + 1]] <- list(i = i, 
        x = x)
    invisible(c(".Call", "_FeatureHashing_pair_sort", "FeatureHashing", 
    "i", "x"))
}
