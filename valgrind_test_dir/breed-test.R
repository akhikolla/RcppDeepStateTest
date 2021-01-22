function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["breed"]][[length(e[["breed"]]) + 1]] <- list()
    list(NULL, character(0))
}
