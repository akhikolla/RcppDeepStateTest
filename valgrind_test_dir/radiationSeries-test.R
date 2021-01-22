function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["radiationSeries"]][[length(e[["radiationSeries"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
