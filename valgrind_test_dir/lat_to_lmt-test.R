function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["lat_to_lmt"]][[length(e[["lat_to_lmt"]]) + 1]] <- list()
    list(NULL, character(0))
}
