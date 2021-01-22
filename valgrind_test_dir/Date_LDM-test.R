function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Date_LDM"]][[length(e[["Date_LDM"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_Date_LDM", x)
}
