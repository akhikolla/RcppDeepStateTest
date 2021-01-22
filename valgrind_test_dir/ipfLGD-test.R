function (train, test, sd, epsilon) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipfLGD"]][[length(e[["ipfLGD"]]) + 1]] <- list(train = train, 
        test = test, sd = sd, epsilon = epsilon)
    .Call("_ipft_ipfLGD", PACKAGE = "ipft", train, test, sd, 
        epsilon)
}
