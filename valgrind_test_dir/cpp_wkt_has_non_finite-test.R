function (wkt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_wkt_has_non_finite"]][[length(e[["cpp_wkt_has_non_finite"]]) + 
        1]] <- list(wkt = wkt)
    .Call("_wkutils_cpp_wkt_has_non_finite", wkt)
}
