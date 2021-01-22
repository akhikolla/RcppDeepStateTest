function (names, element) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_"]][[length(e[["get_"]]) + 1]] <- list(names = names, 
        element = element)
    .Call("_humaniformat_get_", PACKAGE = "humaniformat", names, 
        element)
}
