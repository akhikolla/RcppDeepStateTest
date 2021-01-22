function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["row_overlap"]][[length(e[["row_overlap"]]) + 1]] <- list()
    list(NULL, character(0))
}
