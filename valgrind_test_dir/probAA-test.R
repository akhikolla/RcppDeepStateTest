function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["probAA"]][[length(e[["probAA"]]) + 1]] <- list()
    list(NULL, character(0))
}
