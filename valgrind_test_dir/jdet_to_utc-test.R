function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["jdet_to_utc"]][[length(e[["jdet_to_utc"]]) + 1]] <- list()
    list(NULL, character(0))
}
