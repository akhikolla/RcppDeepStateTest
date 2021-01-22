function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["postmdiag"]][[length(e[["postmdiag"]]) + 1]] <- list()
    list(NULL, character(0))
}
