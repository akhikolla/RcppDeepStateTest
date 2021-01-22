function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CppSuccDate"]][[length(e[["CppSuccDate"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_CppSuccDate", x)
}
