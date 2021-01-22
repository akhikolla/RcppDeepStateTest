function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["vapourPressureFromRH"]][[length(e[["vapourPressureFromRH"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
