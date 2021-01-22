function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["erfcpp"]][[length(e[["erfcpp"]]) + 1]] <- list(x = x)
    .Call("_RJafroc_erfcpp", PACKAGE = "RJafroc", x)
}
