function (names) 
{
    e <- get("data.env", .GlobalEnv)
    e[["format_period"]][[length(e[["format_period"]]) + 1]] <- list(names = names)
    .Call("_humaniformat_format_period", PACKAGE = "humaniformat", 
        names)
}
