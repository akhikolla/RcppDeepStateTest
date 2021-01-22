function (yhat, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["NSE"]][[length(e[["NSE"]]) + 1]] <- list(yhat = yhat, 
        y = y)
    .Call("_ldsr_NSE", yhat, y)
}
