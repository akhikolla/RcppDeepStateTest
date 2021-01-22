function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["relativeHumidityFromMinMaxTemp"]][[length(e[["relativeHumidityFromMinMaxTemp"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
