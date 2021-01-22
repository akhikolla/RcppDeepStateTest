function (x, lag = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pchanges"]][[length(e[["pchanges"]]) + 1]] <- list(x = x, 
        lag = lag)
    .Call("_stocks_pchanges", x, lag)
}
