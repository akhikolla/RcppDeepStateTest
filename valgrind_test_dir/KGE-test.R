function (yhat, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["KGE"]][[length(e[["KGE"]]) + 1]] <- list(yhat = yhat, 
        y = y)
    .Call("_ldsr_KGE", yhat, y)
}
