function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["solarDeclination"]][[length(e[["solarDeclination"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
