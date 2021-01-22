function (lon1, lat1, lon2, lat2, a, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_geoddist"]][[length(e[["do_geoddist"]]) + 1]] <- list(lon1 = lon1, 
        lat1 = lat1, lon2 = lon2, lat2 = lat2, a = a, f = f)
    .Call("_oce_do_geoddist", lon1, lat1, lon2, lat2, a, f)
}
