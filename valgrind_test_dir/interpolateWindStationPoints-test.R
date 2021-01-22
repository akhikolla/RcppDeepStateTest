function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolateWindStationPoints"]][[length(e[["interpolateWindStationPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
