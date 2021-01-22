function (lon, lat, lonr, latr, a, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_geod_xy"]][[length(e[["do_geod_xy"]]) + 1]] <- list(lon = lon, 
        lat = lat, lonr = lonr, latr = latr, a = a, f = f)
    .Call("_oce_do_geod_xy", lon, lat, lonr, latr, a, f)
}
