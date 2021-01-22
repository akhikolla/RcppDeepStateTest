function (wkt, maxCoords) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_format_wkt"]][[length(e[["cpp_format_wkt"]]) + 1]] <- list(wkt = wkt, 
        maxCoords = maxCoords)
    .Call("_wk_cpp_format_wkt", wkt, maxCoords)
}
