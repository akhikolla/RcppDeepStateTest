function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolateTemperatureSeriesPoints"]][[length(e[["interpolateTemperatureSeriesPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
