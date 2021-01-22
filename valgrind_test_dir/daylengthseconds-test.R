function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["daylengthseconds"]][[length(e[["daylengthseconds"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
