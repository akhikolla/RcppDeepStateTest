function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["locusIBS"]][[length(e[["locusIBS"]]) + 1]] <- list()
    list(NULL, character(0))
}
