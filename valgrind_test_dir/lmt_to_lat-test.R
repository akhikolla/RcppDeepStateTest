function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["lmt_to_lat"]][[length(e[["lmt_to_lat"]]) + 1]] <- list()
    list(NULL, character(0))
}
