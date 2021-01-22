function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["doSpmax"]][[length(e[["doSpmax"]]) + 1]] <- list()
    list(NULL, character(0))
}
