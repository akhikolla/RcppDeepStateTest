function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["sunRiseSet"]][[length(e[["sunRiseSet"]]) + 1]] <- list()
    list(NULL, character(0))
}
