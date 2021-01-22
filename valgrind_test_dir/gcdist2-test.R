function (lon1, lat1, lon2, lat2, eps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gcdist2"]][[length(e[["gcdist2"]]) + 1]] <- list(lon1 = lon1, 
        lat1 = lat1, lon2 = lon2, lat2 = lat2, eps = eps)
    .Call("_gear_gcdist2", lon1, lat1, lon2, lat2, eps)
}
