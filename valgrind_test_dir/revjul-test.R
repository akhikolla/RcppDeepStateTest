function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["revjul"]][[length(e[["revjul"]]) + 1]] <- list()
    list(NULL, character(0))
}
