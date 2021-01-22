function (values, n = 2L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rolling_groups"]][[length(e[["rolling_groups"]]) + 1]] <- list(values = values, 
        n = n)
    .Call("_PAutilities_rolling_groups", values, n)
}
