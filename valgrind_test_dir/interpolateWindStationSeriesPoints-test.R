function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolateWindStationSeriesPoints"]][[length(e[["interpolateWindStationSeriesPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
