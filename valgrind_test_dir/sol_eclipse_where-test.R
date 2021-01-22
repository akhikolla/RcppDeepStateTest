function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["sol_eclipse_where"]][[length(e[["sol_eclipse_where"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
