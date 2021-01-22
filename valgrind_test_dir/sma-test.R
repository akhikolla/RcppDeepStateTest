function (x, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sma"]][[length(e[["sma"]]) + 1]] <- list(x = x, n = n)
    .Call("_QuantTools_sma", x, n)
}
