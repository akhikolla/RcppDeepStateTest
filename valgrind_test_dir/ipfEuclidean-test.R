function (train, test) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipfEuclidean"]][[length(e[["ipfEuclidean"]]) + 1]] <- list(train = train, 
        test = test)
    .Call("_ipft_ipfEuclidean", PACKAGE = "ipft", train, test)
}
