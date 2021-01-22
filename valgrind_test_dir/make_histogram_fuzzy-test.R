function (ordered, interval) 
{
    e <- get("data.env", .GlobalEnv)
    e[["make_histogram_fuzzy"]][[length(e[["make_histogram_fuzzy"]]) + 
        1]] <- list(ordered = ordered, interval = interval)
    .Call("_imagerExtra_make_histogram_fuzzy", ordered, interval)
}
