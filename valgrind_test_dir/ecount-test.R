function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["ecount"]][[length(e[["ecount"]]) + 1]] <- list()
    list(NULL, character(0))
}
