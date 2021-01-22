function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["locusLRmix_Caller"]][[length(e[["locusLRmix_Caller"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
