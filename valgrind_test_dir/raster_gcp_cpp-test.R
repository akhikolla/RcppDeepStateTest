function (filename) 
{
    e <- get("data.env", .GlobalEnv)
    e[["raster_gcp_cpp"]][[length(e[["raster_gcp_cpp"]]) + 1]] <- list(filename = filename)
    .Call("_vapour_raster_gcp_cpp", PACKAGE = "vapour", filename)
}
