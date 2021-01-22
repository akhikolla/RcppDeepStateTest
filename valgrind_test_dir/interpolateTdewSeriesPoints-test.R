function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolateTdewSeriesPoints"]][[length(e[["interpolateTdewSeriesPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
