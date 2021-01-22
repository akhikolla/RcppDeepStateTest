function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["erfVect"]][[length(e[["erfVect"]]) + 1]] <- list(x = x)
    .Call("_RJafroc_erfVect", PACKAGE = "RJafroc", x)
}
