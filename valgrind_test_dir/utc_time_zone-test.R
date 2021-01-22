function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["utc_time_zone"]][[length(e[["utc_time_zone"]]) + 1]] <- list()
    list(NULL, character(0))
}
