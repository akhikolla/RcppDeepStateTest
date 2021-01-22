function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DaysInMonth"]][[length(e[["DaysInMonth"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_DaysInMonth", x)
}
