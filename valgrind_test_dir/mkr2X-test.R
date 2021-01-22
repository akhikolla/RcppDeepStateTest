function (Y, K1, K2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mkr2X"]][[length(e[["mkr2X"]]) + 1]] <- list(Y = Y, K1 = K1, 
        K2 = K2)
    .Call("_NAM_mkr2X", Y, K1, K2)
}
