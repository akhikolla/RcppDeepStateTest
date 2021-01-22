function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["date_checkCpp"]][[length(e[["date_checkCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
