function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolatePrecipitationSeriesPoints"]][[length(e[["interpolatePrecipitationSeriesPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
