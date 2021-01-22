function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["airDensity"]][[length(e[["airDensity"]]) + 1]] <- list()
    list(NULL, character(0))
}
