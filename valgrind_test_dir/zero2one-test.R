function (samples) 
{
    e <- get("data.env", .GlobalEnv)
    e[["zero2one"]][[length(e[["zero2one"]]) + 1]] <- list(samples = samples)
    .Call("_AGread_zero2one", PACKAGE = "AGread", samples)
}
