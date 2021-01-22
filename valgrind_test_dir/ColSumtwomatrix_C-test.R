function (AA, BB) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ColSumtwomatrix_C"]][[length(e[["ColSumtwomatrix_C"]]) + 
        1]] <- list(AA = AA, BB = BB)
    .Call("_CKLRT_ColSumtwomatrix_C", PACKAGE = "CKLRT", AA, 
        BB)
}
