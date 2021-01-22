function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["mStat"]][[length(e[["mStat"]]) + 1]] <- list()
    list(NULL, character(0))
}
