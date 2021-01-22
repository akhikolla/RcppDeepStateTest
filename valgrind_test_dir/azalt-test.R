function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["azalt"]][[length(e[["azalt"]]) + 1]] <- list()
    list(NULL, character(0))
}
