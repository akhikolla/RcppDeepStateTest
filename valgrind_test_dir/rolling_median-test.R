function (x, win) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rolling_median"]][[length(e[["rolling_median"]]) + 1]] <- list(x = x, 
        win = win)
    .Call("_amt_rolling_median", PACKAGE = "amt", x, win)
}
