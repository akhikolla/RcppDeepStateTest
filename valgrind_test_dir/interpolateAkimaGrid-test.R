function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolateAkimaGrid"]][[length(e[["interpolateAkimaGrid"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
