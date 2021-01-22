function (X, Y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MATMULT"]][[length(e[["MATMULT"]]) + 1]] <- list(X = X, 
        Y = Y)
    .Call("_Phase12Compare_MATMULT", PACKAGE = "Phase12Compare", 
        X, Y)
}
