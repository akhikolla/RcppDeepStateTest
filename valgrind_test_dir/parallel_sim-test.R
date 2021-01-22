function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["parallel_sim"]][[length(e[["parallel_sim"]]) + 1]] <- list()
    list(NULL, character(0))
}
