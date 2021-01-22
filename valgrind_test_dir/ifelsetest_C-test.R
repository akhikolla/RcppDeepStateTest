function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ifelsetest_C"]][[length(e[["ifelsetest_C"]]) + 1]] <- list(x = x)
    .Call("_CKLRT_ifelsetest_C", PACKAGE = "CKLRT", x)
}
