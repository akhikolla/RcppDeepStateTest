function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mdd_p"]][[length(e[["mdd_p"]]) + 1]] <- list(x = x)
    .Call("_stocks_mdd_p", x)
}
