function (resid, y, thetamat, j, n, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["updateresidual"]][[length(e[["updateresidual"]]) + 1]] <- list(resid = resid, 
        y = y, thetamat = thetamat, j = j, n = n, p = p)
    invisible(c(".Call", "_flam_updateresidual", "flam", "resid", 
    "y", "thetamat", "j", "n", "p"))
}
