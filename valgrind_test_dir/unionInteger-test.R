function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["unionInteger"]][[length(e[["unionInteger"]]) + 1]] <- list()
    list(NULL, character(0))
}
