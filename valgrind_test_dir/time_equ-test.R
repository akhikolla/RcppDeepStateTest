function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["time_equ"]][[length(e[["time_equ"]]) + 1]] <- list()
    list(NULL, character(0))
}
