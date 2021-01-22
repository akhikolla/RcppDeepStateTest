function (train, test, sd, epsilon, alpha, threshold) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipfPLGD"]][[length(e[["ipfPLGD"]]) + 1]] <- list(train = train, 
        test = test, sd = sd, epsilon = epsilon, alpha = alpha, 
        threshold = threshold)
    .Call("_ipft_ipfPLGD", PACKAGE = "ipft", train, test, sd, 
        epsilon, alpha, threshold)
}
