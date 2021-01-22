function (a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["concatenate_and_sort"]][[length(e[["concatenate_and_sort"]]) + 
        1]] <- list(a = a, b = b)
    .Call("_HistDAWass_concatenate_and_sort", PACKAGE = "HistDAWass", 
        a, b)
}
