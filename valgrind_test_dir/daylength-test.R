function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["daylength"]][[length(e[["daylength"]]) + 1]] <- list()
    list(NULL, character(0))
}
