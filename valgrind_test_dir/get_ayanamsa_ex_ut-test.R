function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_ayanamsa_ex_ut"]][[length(e[["get_ayanamsa_ex_ut"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
