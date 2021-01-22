function (newEndT, verbose) 
{
    e <- get("data.env", .GlobalEnv)
    e[["modifyTEnd"]][[length(e[["modifyTEnd"]]) + 1]] <- list(newEndT = newEndT, 
        verbose = verbose)
    invisible(c(".Call", "'_abcADM_modifyTEnd`", "newEndT", "verbose"
    ))
}
