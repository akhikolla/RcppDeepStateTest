function (X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["IMP"]][[length(e[["IMP"]]) + 1]] <- list(X = X)
    .Call("_NAM_IMP", X)
}
