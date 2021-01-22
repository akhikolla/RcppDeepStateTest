function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["shullDeltri"]][[length(e[["shullDeltri"]]) + 1]] <- list()
    list(NULL, character(0))
}
