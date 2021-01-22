function (AA) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Elementwisesquare_C"]][[length(e[["Elementwisesquare_C"]]) + 
        1]] <- list(AA = AA)
    .Call("_CKLRT_Elementwisesquare_C", PACKAGE = "CKLRT", AA)
}
