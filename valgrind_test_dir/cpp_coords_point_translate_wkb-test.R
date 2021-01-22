function (x, y, z, m, endian, bufferSize) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_coords_point_translate_wkb"]][[length(e[["cpp_coords_point_translate_wkb"]]) + 
        1]] <- list(x = x, y = y, z = z, m = m, endian = endian, 
        bufferSize = bufferSize)
    .Call("_wkutils_cpp_coords_point_translate_wkb", x, y, z, 
        m, endian, bufferSize)
}
