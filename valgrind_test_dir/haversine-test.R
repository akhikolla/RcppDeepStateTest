function (lat1, lon1, lat2, lon2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["haversine"]][[length(e[["haversine"]]) + 1]] <- list(lat1 = lat1, 
        lon1 = lon1, lat2 = lat2, lon2 = lon2)
    .Call("_hans_haversine", lat1, lon1, lat2, lon2)
}
