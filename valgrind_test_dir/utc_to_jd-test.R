function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["utc_to_jd"]][[length(e[["utc_to_jd"]]) + 1]] <- list()
    list(NULL, character(0))
}
