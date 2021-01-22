function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_planet_name"]][[length(e[["get_planet_name"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
