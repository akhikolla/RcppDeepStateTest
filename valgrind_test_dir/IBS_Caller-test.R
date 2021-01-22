function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["IBS_Caller"]][[length(e[["IBS_Caller"]]) + 1]] <- list()
    list(NULL, character(0))
}
