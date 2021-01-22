function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["getWindFieldIndexAndFactor"]][[length(e[["getWindFieldIndexAndFactor"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
