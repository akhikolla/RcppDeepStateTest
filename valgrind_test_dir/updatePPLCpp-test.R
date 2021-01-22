function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["updatePPLCpp"]][[length(e[["updatePPLCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
