function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sort_unique_C"]][[length(e[["sort_unique_C"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_sort_unique_C", x)
}
