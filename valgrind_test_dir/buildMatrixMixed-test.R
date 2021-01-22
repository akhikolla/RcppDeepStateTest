function (v, rowInd, colInd, colNames, nRows, nCols, charCols, 
    dateCols) 
{
    e <- get("data.env", .GlobalEnv)
    e[["buildMatrixMixed"]][[length(e[["buildMatrixMixed"]]) + 
        1]] <- list(v = v, rowInd = rowInd, colInd = colInd, 
        colNames = colNames, nRows = nRows, nCols = nCols, charCols = charCols, 
        dateCols = dateCols)
    .Call("_openxlsx_buildMatrixMixed", v, rowInd, colInd, colNames, 
        nRows, nCols, charCols, dateCols)
}
