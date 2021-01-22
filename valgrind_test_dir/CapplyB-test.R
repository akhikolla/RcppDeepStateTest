function (us, X, mu) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CapplyB"]][[length(e[["CapplyB"]]) + 1]] <- list(us = us, 
        X = X, mu = mu)
    .Call("_robFitConGraph_CapplyB", us, X, mu)
}
