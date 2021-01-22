function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stl_sort"]][[length(e[["stl_sort"]]) + 1]] <- list(x = x)
    .Call("_icosa_stl_sort", x)
}
