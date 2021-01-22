function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["slope"]][[length(e[["slope"]]) + 1]] <- list()
    list(NULL, character(0))
}
