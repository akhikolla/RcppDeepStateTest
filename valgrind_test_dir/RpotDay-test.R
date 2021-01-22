function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["RpotDay"]][[length(e[["RpotDay"]]) + 1]] <- list()
    list(NULL, character(0))
}
