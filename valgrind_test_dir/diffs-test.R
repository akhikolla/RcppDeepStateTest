function (x, lag = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["diffs"]][[length(e[["diffs"]]) + 1]] <- list(x = x, lag = lag)
    .Call("_stocks_diffs", x, lag)
}
