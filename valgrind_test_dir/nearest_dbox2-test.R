function (lat_lon1d, lat_lon2d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nearest_dbox2"]][[length(e[["nearest_dbox2"]]) + 1]] <- list(lat_lon1d = lat_lon1d, 
        lat_lon2d = lat_lon2d)
    .Call("_Rvoterdistance_nearest_dbox2", lat_lon1d, lat_lon2d)
}
