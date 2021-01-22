function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["leap"]][[length(e[["leap"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_leap", x)
}
