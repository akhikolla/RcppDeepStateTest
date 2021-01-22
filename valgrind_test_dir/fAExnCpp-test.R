function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["fAExnCpp"]][[length(e[["fAExnCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
