function (Y, X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mrr"]][[length(e[["mrr"]]) + 1]] <- list(Y = Y, X = X)
    .Call("_NAM_mrr", Y, X)
}
