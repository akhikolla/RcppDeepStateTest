function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["ViterbiPP"]][[length(e[["ViterbiPP"]]) + 1]] <- list()
    list(NULL, character(0))
}
