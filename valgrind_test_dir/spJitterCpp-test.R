function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["spJitterCpp"]][[length(e[["spJitterCpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
