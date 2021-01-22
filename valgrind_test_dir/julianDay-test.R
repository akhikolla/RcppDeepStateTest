function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["julianDay"]][[length(e[["julianDay"]]) + 1]] <- list()
    list(NULL, character(0))
}
