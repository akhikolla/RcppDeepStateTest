function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["skyLongwaveRadiation"]][[length(e[["skyLongwaveRadiation"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
