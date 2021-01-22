function (lat1d, lon1d, lat2d, lon2d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["distanceEarth"]][[length(e[["distanceEarth"]]) + 1]] <- list(lat1d = lat1d, 
        lon1d = lon1d, lat2d = lat2d, lon2d = lon2d)
    .Call("_Rvoterdistance_distanceEarth", lat1d, lon1d, lat2d, 
        lon2d)
}
