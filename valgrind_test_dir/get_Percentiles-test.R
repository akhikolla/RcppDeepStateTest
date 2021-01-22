function (x, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_Percentiles"]][[length(e[["get_Percentiles"]]) + 
        1]] <- list(x = x, p = p)
    .Call("_ptsuite_get_Percentiles", PACKAGE = "ptsuite", x, 
        p)
}
