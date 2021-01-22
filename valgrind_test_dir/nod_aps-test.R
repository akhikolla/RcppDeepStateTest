function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["nod_aps"]][[length(e[["nod_aps"]]) + 1]] <- list()
    list(NULL, character(0))
}
