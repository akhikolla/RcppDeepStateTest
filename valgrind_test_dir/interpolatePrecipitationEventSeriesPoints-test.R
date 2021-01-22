function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolatePrecipitationEventSeriesPoints"]][[length(e[["interpolatePrecipitationEventSeriesPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
