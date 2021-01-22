function (one) 
{
    e <- get("data.env", .GlobalEnv)
    e[["whichMinVector_"]][[length(e[["whichMinVector_"]]) + 
        1]] <- list(one = one)
    .Call("_icosa_whichMinVector_", one)
}
