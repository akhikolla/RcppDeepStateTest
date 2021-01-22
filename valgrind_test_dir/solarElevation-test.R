function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["solarElevation"]][[length(e[["solarElevation"]]) + 1]] <- list()
    list(NULL, character(0))
}
