function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["ViterbiD"]][[length(e[["ViterbiD"]]) + 1]] <- list()
    list(NULL, character(0))
}
