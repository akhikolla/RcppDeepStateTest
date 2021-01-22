function (Y, K) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mkr"]][[length(e[["mkr"]]) + 1]] <- list(Y = Y, K = K)
    .Call("_NAM_mkr", Y, K)
}
