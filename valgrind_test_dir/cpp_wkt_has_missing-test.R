function (wkt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_wkt_has_missing"]][[length(e[["cpp_wkt_has_missing"]]) + 
        1]] <- list(wkt = wkt)
    .Call("_wkutils_cpp_wkt_has_missing", wkt)
}
