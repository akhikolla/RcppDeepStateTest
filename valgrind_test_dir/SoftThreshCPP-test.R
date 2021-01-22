function (x, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SoftThreshCPP"]][[length(e[["SoftThreshCPP"]]) + 1]] <- list(x = x, 
        lambda = lambda)
    .Call("_biClassify_SoftThreshCPP", PACKAGE = "biClassify", 
        x, lambda)
}
