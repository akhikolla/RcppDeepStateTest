function (x, win) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rolling_mean"]][[length(e[["rolling_mean"]]) + 1]] <- list(x = x, 
        win = win)
    .Call("_amt_rolling_mean", PACKAGE = "amt", x, win)
}
