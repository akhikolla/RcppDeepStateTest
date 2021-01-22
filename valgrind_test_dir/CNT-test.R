function (X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CNT"]][[length(e[["CNT"]]) + 1]] <- list(X = X)
    .Call("_NAM_CNT", X)
}
