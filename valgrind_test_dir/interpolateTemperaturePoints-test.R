function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolateTemperaturePoints"]][[length(e[["interpolateTemperaturePoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
