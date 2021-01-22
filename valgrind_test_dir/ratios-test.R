function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ratios"]][[length(e[["ratios"]]) + 1]] <- list(x = x)
    .Call("_stocks_ratios", x)
}
