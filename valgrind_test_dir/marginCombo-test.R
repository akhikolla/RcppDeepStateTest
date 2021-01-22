function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["marginCombo"]][[length(e[["marginCombo"]]) + 1]] <- list()
    list(NULL, character(0))
}
