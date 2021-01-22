function (numbers, ranges) 
{
    e <- get("data.env", .GlobalEnv)
    e[["which_interval_"]][[length(e[["which_interval_"]]) + 
        1]] <- list(numbers = numbers, ranges = ranges)
    .Call("_nandb_which_interval_", numbers, ranges)
}
