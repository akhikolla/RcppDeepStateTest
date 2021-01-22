function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_orbital_elements"]][[length(e[["get_orbital_elements"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
