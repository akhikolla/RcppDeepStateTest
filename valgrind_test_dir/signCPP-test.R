function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["signCPP"]][[length(e[["signCPP"]]) + 1]] <- list(x = x)
    .Call("_biClassify_signCPP", PACKAGE = "biClassify", x)
}
