function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["pack"]][[length(e[["pack"]]) + 1]] <- list()
    list(NULL, character(0))
}
