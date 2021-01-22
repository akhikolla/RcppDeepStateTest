function (newnPerTheta, verbose) 
{
    e <- get("data.env", .GlobalEnv)
    e[["modifynPerTheta"]][[length(e[["modifynPerTheta"]]) + 
        1]] <- list(newnPerTheta = newnPerTheta, verbose = verbose)
    invisible(c(".Call", "'_abcADM_modifynPerTheta`", "newnPerTheta", 
    "verbose"))
}
