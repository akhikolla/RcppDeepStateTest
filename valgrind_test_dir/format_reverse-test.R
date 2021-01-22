function (names) 
{
    e <- get("data.env", .GlobalEnv)
    e[["format_reverse"]][[length(e[["format_reverse"]]) + 1]] <- list(names = names)
    .Call("_humaniformat_format_reverse", PACKAGE = "humaniformat", 
        names)
}
