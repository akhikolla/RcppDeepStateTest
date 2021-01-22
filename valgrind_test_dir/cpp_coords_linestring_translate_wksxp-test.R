function (x, y, z, m, featureId) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_coords_linestring_translate_wksxp"]][[length(e[["cpp_coords_linestring_translate_wksxp"]]) + 
        1]] <- list(x = x, y = y, z = z, m = m, featureId = featureId)
    .Call("_wkutils_cpp_coords_linestring_translate_wksxp", x, 
        y, z, m, featureId)
}
