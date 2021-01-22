function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["power_curve"]][[length(e[["power_curve"]]) + 1]] <- list()
    list(NULL, character(0))
}
