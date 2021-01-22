function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["mult3sum"]][[length(e[["mult3sum"]]) + 1]] <- list()
    list(NULL, character(0))
}
