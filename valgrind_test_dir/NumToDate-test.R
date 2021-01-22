function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["NumToDate"]][[length(e[["NumToDate"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_NumToDate", x)
}
