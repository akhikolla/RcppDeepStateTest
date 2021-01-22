function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["h2"]][[length(e[["h2"]]) + 1]] <- list()
    list(NULL, character(0))
}
