function (filename, window, band = 1L, resample = "nearestneighbour") 
{
    e <- get("data.env", .GlobalEnv)
    e[["raster_io_cpp"]][[length(e[["raster_io_cpp"]]) + 1]] <- list(filename = filename, 
        window = window, band = band, resample = resample)
    .Call("_vapour_raster_io_cpp", PACKAGE = "vapour", filename, 
        window, band, resample)
}
