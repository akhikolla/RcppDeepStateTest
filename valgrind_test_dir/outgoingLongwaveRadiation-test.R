function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["outgoingLongwaveRadiation"]][[length(e[["outgoingLongwaveRadiation"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
