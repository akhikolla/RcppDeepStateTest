function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["atmosphericPressure"]][[length(e[["atmosphericPressure"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
