function (y, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightedVarRcppN"]][[length(e[["weightedVarRcppN"]]) + 
        1]] <- list(y = y, w = w)
    .Call("_carSurv_weightedVarRcppN", y, w)
}
