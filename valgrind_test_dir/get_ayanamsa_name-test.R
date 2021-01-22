function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_ayanamsa_name"]][[length(e[["get_ayanamsa_name"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
