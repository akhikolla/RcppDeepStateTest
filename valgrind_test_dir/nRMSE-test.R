function (yhat, y, normConst) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nRMSE"]][[length(e[["nRMSE"]]) + 1]] <- list(yhat = yhat, 
        y = y, normConst = normConst)
    .Call("_ldsr_nRMSE", yhat, y, normConst)
}
