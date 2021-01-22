function (X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GAU"]][[length(e[["GAU"]]) + 1]] <- list(X = X)
    .Call("_NAM_GAU", X)
}
