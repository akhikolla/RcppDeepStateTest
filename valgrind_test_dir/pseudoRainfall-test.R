function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["pseudoRainfall"]][[length(e[["pseudoRainfall"]]) + 1]] <- list()
    list(NULL, character(0))
}
