function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stl_sort_reverse_NA"]][[length(e[["stl_sort_reverse_NA"]]) + 
        1]] <- list(x = x)
    .Call("_BoostMLR_stl_sort_reverse_NA", x)
}
