function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["doSpmin"]][[length(e[["doSpmin"]]) + 1]] <- list()
    list(NULL, character(0))
}
