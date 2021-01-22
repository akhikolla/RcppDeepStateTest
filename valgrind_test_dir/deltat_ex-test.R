function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["deltat_ex"]][[length(e[["deltat_ex"]]) + 1]] <- list()
    list(NULL, character(0))
}
