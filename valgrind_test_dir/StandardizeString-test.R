function (strings) 
{
    e <- get("data.env", .GlobalEnv)
    e[["StandardizeString"]][[length(e[["StandardizeString"]]) + 
        1]] <- list(strings = strings)
    .Call("_PPRL_StandardizeString", PACKAGE = "PPRL", strings)
}
