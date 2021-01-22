function (AA) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MatrixRowMax_C"]][[length(e[["MatrixRowMax_C"]]) + 1]] <- list(AA = AA)
    .Call("_CKLRT_MatrixRowMax_C", PACKAGE = "CKLRT", AA)
}
