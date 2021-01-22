function (Y, X1, X2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mrr2X"]][[length(e[["mrr2X"]]) + 1]] <- list(Y = Y, X1 = X1, 
        X2 = X2)
    .Call("_NAM_mrr2X", Y, X1, X2)
}
