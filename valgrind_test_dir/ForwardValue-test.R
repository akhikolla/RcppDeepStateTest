function (value, valueLower, valueUpper) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ForwardValue"]][[length(e[["ForwardValue"]]) + 1]] <- list(value = value, 
        valueLower = valueLower, valueUpper = valueUpper)
    .Call("_RJafroc_ForwardValue", PACKAGE = "RJafroc", value, 
        valueLower, valueUpper)
}
