function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["azalt_rev"]][[length(e[["azalt_rev"]]) + 1]] <- list()
    list(NULL, character(0))
}
