function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LDM"]][[length(e[["LDM"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_LDM", x)
}
