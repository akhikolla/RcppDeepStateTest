function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sumC"]][[length(e[["sumC"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_sumC", x)
}
