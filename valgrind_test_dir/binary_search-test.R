function (array, pattern) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binary_search"]][[length(e[["binary_search"]]) + 1]] <- list(array = array, 
        pattern = pattern)
    .Call("_BNSL_binary_search", array, pattern)
}
