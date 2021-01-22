function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["dailyEquilibriumPET"]][[length(e[["dailyEquilibriumPET"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
