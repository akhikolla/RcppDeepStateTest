function (newdt, verbose) 
{
    e <- get("data.env", .GlobalEnv)
    e[["modifyTimeStep"]][[length(e[["modifyTimeStep"]]) + 1]] <- list(newdt = newdt, 
        verbose = verbose)
    invisible(c(".Call", "'_abcADM_modifyTimeStep`", "newdt", 
    "verbose"))
}
