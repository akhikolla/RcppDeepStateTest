function (wkt, includeZ, includeM, includeSRID) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_wkt_translate_wksxp"]][[length(e[["cpp_wkt_translate_wksxp"]]) + 
        1]] <- list(wkt = wkt, includeZ = includeZ, includeM = includeM, 
        includeSRID = includeSRID)
    .Call("_wk_cpp_wkt_translate_wksxp", wkt, includeZ, includeM, 
        includeSRID)
}
