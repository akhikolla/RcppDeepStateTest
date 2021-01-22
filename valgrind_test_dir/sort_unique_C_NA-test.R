function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sort_unique_C_NA"]][[length(e[["sort_unique_C_NA"]]) + 
        1]] <- list(x = x)
    .Call("_BoostMLR_sort_unique_C_NA", x)
}
