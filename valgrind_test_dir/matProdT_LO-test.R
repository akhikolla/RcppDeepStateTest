function (X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["matProdT_LO"]][[length(e[["matProdT_LO"]]) + 1]] <- list(X = X)
    .Call("_Benchmarking_matProdT_LO", X)
}
