function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["day_of_week"]][[length(e[["day_of_week"]]) + 1]] <- list()
    list(NULL, character(0))
}
