function (AA) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ColSum_C"]][[length(e[["ColSum_C"]]) + 1]] <- list(AA = AA)
    .Call("_CKLRT_ColSum_C", PACKAGE = "CKLRT", AA)
}
