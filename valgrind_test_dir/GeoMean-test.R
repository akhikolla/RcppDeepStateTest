function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GeoMean"]][[length(e[["GeoMean"]]) + 1]] <- list(x = x)
    .Call("_ptsuite_GeoMean", PACKAGE = "ptsuite", x)
}
