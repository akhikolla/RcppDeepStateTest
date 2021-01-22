function (Y, X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mrrV2"]][[length(e[["mrrV2"]]) + 1]] <- list(Y = Y, X = X)
    .Call("_NAM_mrrV2", Y, X)
}
