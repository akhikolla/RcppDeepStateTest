function (AA) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Sum_C"]][[length(e[["Sum_C"]]) + 1]] <- list(AA = AA)
    .Call("_CKLRT_Sum_C", PACKAGE = "CKLRT", AA)
}
