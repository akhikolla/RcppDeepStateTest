function (v, rowInd, colInd, colNames, nRows, nCols) 
{
    e <- get("data.env", .GlobalEnv)
    e[["buildMatrixNumeric"]][[length(e[["buildMatrixNumeric"]]) + 
        1]] <- list(v = v, rowInd = rowInd, colInd = colInd, 
        colNames = colNames, nRows = nRows, nCols = nCols)
    .Call("_openxlsx_buildMatrixNumeric", v, rowInd, colInd, 
        colNames, nRows, nCols)
}
