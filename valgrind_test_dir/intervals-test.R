function (level, array) 
{
    e <- get("data.env", .GlobalEnv)
    e[["intervals"]][[length(e[["intervals"]]) + 1]] <- list(level = level, 
        array = array)
    .Call("_BNSL_intervals", level, array)
}
