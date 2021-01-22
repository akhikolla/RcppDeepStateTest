function (wkt, includeZ, includeM, includeSRID, endian, bufferSize) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_wkt_translate_wkb"]][[length(e[["cpp_wkt_translate_wkb"]]) + 
        1]] <- list(wkt = wkt, includeZ = includeZ, includeM = includeM, 
        includeSRID = includeSRID, endian = endian, bufferSize = bufferSize)
    .Call("_wk_cpp_wkt_translate_wkb", wkt, includeZ, includeM, 
        includeSRID, endian, bufferSize)
}
