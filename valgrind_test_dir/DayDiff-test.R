function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DayDiff"]][[length(e[["DayDiff"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_DayDiff", x)
}
