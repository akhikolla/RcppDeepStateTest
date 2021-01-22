function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["latentHeatVaporisation"]][[length(e[["latentHeatVaporisation"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
