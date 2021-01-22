function (Y, X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mrrFast"]][[length(e[["mrrFast"]]) + 1]] <- list(Y = Y, 
        X = X)
    .Call("_NAM_mrrFast", Y, X)
}
