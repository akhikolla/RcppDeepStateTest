function (Xm, U1m, U2m, Rv, Cv) 
{
    e <- get("data.env", .GlobalEnv)
    e[["p_updatePseudoData"]][[length(e[["p_updatePseudoData"]]) + 
        1]] <- list(Xm = Xm, U1m = U1m, U2m = U2m, Rv = Rv, Cv = Cv)
    invisible(c(".Call", "'_CMF_p_updatePseudoData`", "Xm", "U1m", 
    "U2m", "Rv", "Cv"))
}
