function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["deltat"]][[length(e[["deltat"]]) + 1]] <- list()
    list(NULL, character(0))
}
