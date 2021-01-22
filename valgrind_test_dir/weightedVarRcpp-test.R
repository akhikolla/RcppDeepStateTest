function (y, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightedVarRcpp"]][[length(e[["weightedVarRcpp"]]) + 
        1]] <- list(y = y, w = w)
    .Call("_carSurv_weightedVarRcpp", y, w)
}
