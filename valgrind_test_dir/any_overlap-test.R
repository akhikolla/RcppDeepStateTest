function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["any_overlap"]][[length(e[["any_overlap"]]) + 1]] <- list()
    list(NULL, character(0))
}
