function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["solarConstant"]][[length(e[["solarConstant"]]) + 1]] <- list()
    list(NULL, character(0))
}
