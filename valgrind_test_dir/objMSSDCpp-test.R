function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["objMSSDCpp"]][[length(e[["objMSSDCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
