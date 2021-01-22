function (x, lag = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pdiffs"]][[length(e[["pdiffs"]]) + 1]] <- list(x = x, 
        lag = lag)
    .Call("_stocks_pdiffs", x, lag)
}
