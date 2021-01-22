function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["potentialRadiationSeries"]][[length(e[["potentialRadiationSeries"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
