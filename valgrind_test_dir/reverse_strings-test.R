function (strings) 
{
    e <- get("data.env", .GlobalEnv)
    e[["reverse_strings"]][[length(e[["reverse_strings"]]) + 
        1]] <- list(strings = strings)
    .Call("_urltools_reverse_strings", strings)
}
