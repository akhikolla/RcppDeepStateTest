function (thetamat, column, colnum, nrow) 
{
    e <- get("data.env", .GlobalEnv)
    e[["updatecolumn"]][[length(e[["updatecolumn"]]) + 1]] <- list(thetamat = thetamat, 
        column = column, colnum = colnum, nrow = nrow)
    invisible(c(".Call", "_flam_updatecolumn", "flam", "thetamat", 
    "column", "colnum", "nrow"))
}
