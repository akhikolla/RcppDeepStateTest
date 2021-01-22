function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["stalta_event_nofreeze"]][[length(e[["stalta_event_nofreeze"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
