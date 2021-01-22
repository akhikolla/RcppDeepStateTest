function (W, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["repeatgenerate"]][[length(e[["repeatgenerate"]]) + 1]] <- list(W = W, 
        lambda = lambda)
    .Call("_augSIMEX_repeatgenerate", PACKAGE = "augSIMEX", W, 
        lambda)
}
