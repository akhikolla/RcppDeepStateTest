function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["fDAxnCpp"]][[length(e[["fDAxnCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
