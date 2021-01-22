function (lat1d_vec, lon1d_vec, lat2d_vec, lon2d_vec) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nearest_dbox"]][[length(e[["nearest_dbox"]]) + 1]] <- list(lat1d_vec = lat1d_vec, 
        lon1d_vec = lon1d_vec, lat2d_vec = lat2d_vec, lon2d_vec = lon2d_vec)
    .Call("_Rvoterdistance_nearest_dbox", lat1d_vec, lon1d_vec, 
        lat2d_vec, lon2d_vec)
}
