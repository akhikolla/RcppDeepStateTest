function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DIST"]][[length(e[["DIST"]]) + 1]] <- list(x = x)
    .Call("_BondValuation_DIST", x)
}
