function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["RDay"]][[length(e[["RDay"]]) + 1]] <- list()
    list(NULL, character(0))
}
