function (valueFwd, valueLower, valueUpper) 
{
    e <- get("data.env", .GlobalEnv)
    e[["InverseValue"]][[length(e[["InverseValue"]]) + 1]] <- list(valueFwd = valueFwd, 
        valueLower = valueLower, valueUpper = valueUpper)
    .Call("_RJafroc_InverseValue", PACKAGE = "RJafroc", valueFwd, 
        valueLower, valueUpper)
}
