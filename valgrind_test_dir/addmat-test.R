function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["addmat"]][[length(e[["addmat"]]) + 1]] <- list()
    list(NULL, character(0))
}
