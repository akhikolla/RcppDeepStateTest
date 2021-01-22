function (from, to, length) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LambdaSeqCpp"]][[length(e[["LambdaSeqCpp"]]) + 1]] <- list(from = from, 
        to = to, length = length)
    .Call("_biClassify_LambdaSeqCpp", PACKAGE = "biClassify", 
        from, to, length)
}
