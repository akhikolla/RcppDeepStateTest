function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_sid_mode"]][[length(e[["set_sid_mode"]]) + 1]] <- list()
    list(NULL, character(0))
}
