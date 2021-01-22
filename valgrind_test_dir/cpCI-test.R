function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpCI"]][[length(e[["cpCI"]]) + 1]] <- list()
    list(NULL, character(0))
}
