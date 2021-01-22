function (yhat, y, yc_bar) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RE"]][[length(e[["RE"]]) + 1]] <- list(yhat = yhat, y = y, 
        yc_bar = yc_bar)
    .Call("_ldsr_RE", yhat, y, yc_bar)
}
