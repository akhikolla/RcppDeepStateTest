function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["netRadiation"]][[length(e[["netRadiation"]]) + 1]] <- list()
    list(NULL, character(0))
}
