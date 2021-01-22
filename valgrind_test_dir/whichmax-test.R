function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["whichmax"]][[length(e[["whichmax"]]) + 1]] <- list()
    list(NULL, character(0))
}
