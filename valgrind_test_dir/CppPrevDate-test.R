function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CppPrevDate"]][[length(e[["CppPrevDate"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_CppPrevDate", x)
}
