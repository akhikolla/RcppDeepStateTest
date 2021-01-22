function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["fAxnCpp"]][[length(e[["fAxnCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
