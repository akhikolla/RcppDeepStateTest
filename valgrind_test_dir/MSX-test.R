function (X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MSX"]][[length(e[["MSX"]]) + 1]] <- list(X = X)
    .Call("_NAM_MSX", X)
}
