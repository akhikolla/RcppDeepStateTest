function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["intersectInteger"]][[length(e[["intersectInteger"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
