function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["averageDaylightTemperature"]][[length(e[["averageDaylightTemperature"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
