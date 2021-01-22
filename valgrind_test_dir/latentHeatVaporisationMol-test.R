function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["latentHeatVaporisationMol"]][[length(e[["latentHeatVaporisationMol"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
