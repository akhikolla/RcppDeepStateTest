function (x, y, z, m, featureId, ringId) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_coords_polygon_translate_wksxp"]][[length(e[["cpp_coords_polygon_translate_wksxp"]]) + 
        1]] <- list(x = x, y = y, z = z, m = m, featureId = featureId, 
        ringId = ringId)
    .Call("_wkutils_cpp_coords_polygon_translate_wksxp", x, y, 
        z, m, featureId, ringId)
}
