function (names) 
{
    e <- get("data.env", .GlobalEnv)
    e[["parse_names"]][[length(e[["parse_names"]]) + 1]] <- list(names = names)
    .Call("_humaniformat_parse_names", PACKAGE = "humaniformat", 
        names)
}
