function (train, test, normVal) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipfNormDistance"]][[length(e[["ipfNormDistance"]]) + 
        1]] <- list(train = train, test = test, normVal = normVal)
    .Call("_ipft_ipfNormDistance", PACKAGE = "ipft", train, test, 
        normVal)
}
