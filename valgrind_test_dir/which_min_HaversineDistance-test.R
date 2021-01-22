function (lat1, lon1, lat2, lon2, upperBound = 10) 
{
    e <- get("data.env", .GlobalEnv)
    e[["which_min_HaversineDistance"]][[length(e[["which_min_HaversineDistance"]]) + 
        1]] <- list(lat1 = lat1, lon1 = lon1, lat2 = lat2, lon2 = lon2, 
        upperBound = upperBound)
    .Call("_hutilscpp_which_min_HaversineDistance", lat1, lon1, 
        lat2, lon2, upperBound)
}
