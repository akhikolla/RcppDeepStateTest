function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["makeWeights"]][[length(e[["makeWeights"]]) + 1]] <- list(x = x)
    .Call("_GeDS_makeWeights", PACKAGE = "GeDS", x)
}
