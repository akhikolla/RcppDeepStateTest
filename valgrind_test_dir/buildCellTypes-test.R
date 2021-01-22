function (classes, nRows) 
{
    e <- get("data.env", .GlobalEnv)
    e[["buildCellTypes"]][[length(e[["buildCellTypes"]]) + 1]] <- list(classes = classes, 
        nRows = nRows)
    .Call("_openxlsx_buildCellTypes", classes, nRows)
}
