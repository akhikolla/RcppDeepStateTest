function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LeapDayInside"]][[length(e[["LeapDayInside"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_LeapDayInside", x)
}
