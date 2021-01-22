function (lon, lat, eps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gcdist1"]][[length(e[["gcdist1"]]) + 1]] <- list(lon = lon, 
        lat = lat, eps = eps)
    .Call("_gear_gcdist1", lon, lat, eps)
}
