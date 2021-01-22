function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["fIAxnCpp"]][[length(e[["fIAxnCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
