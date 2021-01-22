function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["potentialRadiationPoints"]][[length(e[["potentialRadiationPoints"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
