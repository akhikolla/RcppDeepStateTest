function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["sidtime"]][[length(e[["sidtime"]]) + 1]] <- list()
    list(NULL, character(0))
}
