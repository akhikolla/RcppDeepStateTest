function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["relativeHumidityFromDewpointTemp"]][[length(e[["relativeHumidityFromDewpointTemp"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
