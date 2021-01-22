function (pp, iCV, threshold) 
{
    e <- get("data.env", .GlobalEnv)
    e[["credsetmat"]][[length(e[["credsetmat"]]) + 1]] <- list(pp = pp, 
        iCV = iCV, threshold = threshold)
    .Call("_corrcoverage_credsetmat", PACKAGE = "corrcoverage", 
        pp, iCV, threshold)
}
