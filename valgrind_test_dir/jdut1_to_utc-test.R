function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["jdut1_to_utc"]][[length(e[["jdut1_to_utc"]]) + 1]] <- list()
    list(NULL, character(0))
}
