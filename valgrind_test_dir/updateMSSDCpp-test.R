function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["updateMSSDCpp"]][[length(e[["updateMSSDCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
