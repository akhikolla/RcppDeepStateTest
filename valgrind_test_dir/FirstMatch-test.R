function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["FirstMatch"]][[length(e[["FirstMatch"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_FirstMatch", x)
}
