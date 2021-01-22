function (x, y, z, m, featureId, ringId, endian, bufferSize) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_coords_polygon_translate_wkb"]][[length(e[["cpp_coords_polygon_translate_wkb"]]) + 
        1]] <- list(x = x, y = y, z = z, m = m, featureId = featureId, 
        ringId = ringId, endian = endian, bufferSize = bufferSize)
    .Call("_wkutils_cpp_coords_polygon_translate_wkb", x, y, 
        z, m, featureId, ringId, endian, bufferSize)
}
