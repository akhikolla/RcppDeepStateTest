function (source_filename, source_WKT, target_WKT, target_geotransform, 
    target_dim, band) 
{
    e <- get("data.env", .GlobalEnv)
    e[["warp_memory_cpp"]][[length(e[["warp_memory_cpp"]]) + 
        1]] <- list(source_filename = source_filename, source_WKT = source_WKT, 
        target_WKT = target_WKT, target_geotransform = target_geotransform, 
        target_dim = target_dim, band = band)
    .Call("_vapour_warp_memory_cpp", PACKAGE = "vapour", source_filename, 
        source_WKT, target_WKT, target_geotransform, target_dim, 
        band)
}
