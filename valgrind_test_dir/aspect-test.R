function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["aspect"]][[length(e[["aspect"]]) + 1]] <- list()
    list(NULL, character(0))
}
