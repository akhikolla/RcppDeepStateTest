function (highs, lows) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mdd_hl_indices"]][[length(e[["mdd_hl_indices"]]) + 1]] <- list(highs = highs, 
        lows = lows)
    .Call("_stocks_mdd_hl_indices", highs, lows)
}
