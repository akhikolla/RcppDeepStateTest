function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["xi"]][[length(e[["xi"]]) + 1]] <- list()
    list(NULL, character(0))
}
