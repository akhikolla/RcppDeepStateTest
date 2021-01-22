function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_topo"]][[length(e[["set_topo"]]) + 1]] <- list()
    list(NULL, character(0))
}
