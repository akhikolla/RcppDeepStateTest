function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_ayanamsa_ex"]][[length(e[["get_ayanamsa_ex"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
