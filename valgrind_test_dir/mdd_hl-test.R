function (highs, lows) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mdd_hl"]][[length(e[["mdd_hl"]]) + 1]] <- list(highs = highs, 
        lows = lows)
    .Call("_stocks_mdd_hl", highs, lows)
}
