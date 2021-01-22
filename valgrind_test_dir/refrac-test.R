function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["refrac"]][[length(e[["refrac"]]) + 1]] <- list()
    list(NULL, character(0))
}
