function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["acount"]][[length(e[["acount"]]) + 1]] <- list()
    list(NULL, character(0))
}
