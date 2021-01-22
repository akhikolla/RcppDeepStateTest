function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["bscCI"]][[length(e[["bscCI"]]) + 1]] <- list()
    list(NULL, character(0))
}
