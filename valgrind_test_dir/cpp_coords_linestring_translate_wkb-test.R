function (x, y, z, m, featureId, endian, bufferSize) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_coords_linestring_translate_wkb"]][[length(e[["cpp_coords_linestring_translate_wkb"]]) + 
        1]] <- list(x = x, y = y, z = z, m = m, featureId = featureId, 
        endian = endian, bufferSize = bufferSize)
    .Call("_wkutils_cpp_coords_linestring_translate_wkb", x, 
        y, z, m, featureId, endian, bufferSize)
}
