function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["episode_checkCpp"]][[length(e[["episode_checkCpp"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
