function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolatePrecipitationPoints"]][[length(e[["interpolatePrecipitationPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
