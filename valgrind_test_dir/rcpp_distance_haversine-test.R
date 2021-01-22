function (latFrom, lonFrom, latTo, lonTo, tolerance) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_distance_haversine"]][[length(e[["rcpp_distance_haversine"]]) + 
        1]] <- list(latFrom = latFrom, lonFrom = lonFrom, latTo = latTo, 
        lonTo = lonTo, tolerance = tolerance)
    .Call("_gtfs2gps_rcpp_distance_haversine", latFrom, lonFrom, 
        latTo, lonTo, tolerance)
}
