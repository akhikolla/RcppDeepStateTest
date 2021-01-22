function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["kdist"]][[length(e[["kdist"]]) + 1]] <- list()
    list(NULL, character(0))
}
