function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["averageDailyVapourPressure"]][[length(e[["averageDailyVapourPressure"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
