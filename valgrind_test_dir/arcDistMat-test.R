function (X, r) 
{
    e <- get("data.env", .GlobalEnv)
    e[["arcDistMat"]][[length(e[["arcDistMat"]]) + 1]] <- list(X = X, 
        r = r)
    .Call("_signnet_arcDistMat", X, r)
}
