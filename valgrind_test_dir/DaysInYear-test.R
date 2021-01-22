function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DaysInYear"]][[length(e[["DaysInYear"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_DaysInYear", x)
}
