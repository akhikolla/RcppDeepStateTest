function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["nod_aps_ut"]][[length(e[["nod_aps_ut"]]) + 1]] <- list()
    list(NULL, character(0))
}
