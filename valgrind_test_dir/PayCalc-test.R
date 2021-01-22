function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["PayCalc"]][[length(e[["PayCalc"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_PayCalc", x)
}
