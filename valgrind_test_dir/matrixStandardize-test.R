function (X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["matrixStandardize"]][[length(e[["matrixStandardize"]]) + 
        1]] <- list(X = X)
    invisible(c(".Call", "_icensmis_matrixStandardize", "icensmis", 
    "X"))
}
