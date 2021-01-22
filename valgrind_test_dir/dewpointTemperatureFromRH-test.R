function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["dewpointTemperatureFromRH"]][[length(e[["dewpointTemperatureFromRH"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
