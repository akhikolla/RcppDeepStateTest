function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolateTdewPoints"]][[length(e[["interpolateTdewPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
