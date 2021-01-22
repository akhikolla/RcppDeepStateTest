function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["julday"]][[length(e[["julday"]]) + 1]] <- list()
    list(NULL, character(0))
}
