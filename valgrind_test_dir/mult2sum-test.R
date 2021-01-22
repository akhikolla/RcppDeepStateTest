function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["mult2sum"]][[length(e[["mult2sum"]]) + 1]] <- list()
    list(NULL, character(0))
}
