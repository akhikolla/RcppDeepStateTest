function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["dateStringToJulianDays"]][[length(e[["dateStringToJulianDays"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
