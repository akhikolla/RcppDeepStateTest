function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["sol_eclipse_how"]][[length(e[["sol_eclipse_how"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
