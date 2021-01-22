function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["radiationPoints"]][[length(e[["radiationPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
