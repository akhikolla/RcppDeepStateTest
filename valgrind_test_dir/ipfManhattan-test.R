function (train, test) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipfManhattan"]][[length(e[["ipfManhattan"]]) + 1]] <- list(train = train, 
        test = test)
    .Call("_ipft_ipfManhattan", PACKAGE = "ipft", train, test)
}
