function (x, lower, upper) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sorted_range_search"]][[length(e[["sorted_range_search"]]) + 
        1]] <- list(x = x, lower = lower, upper = upper)
    .Call("_tibbletime_sorted_range_search", x, lower, upper)
}
