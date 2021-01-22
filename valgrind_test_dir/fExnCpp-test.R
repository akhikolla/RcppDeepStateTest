function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["fExnCpp"]][[length(e[["fExnCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
