function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["is_overlap"]][[length(e[["is_overlap"]]) + 1]] <- list()
    list(NULL, character(0))
}
