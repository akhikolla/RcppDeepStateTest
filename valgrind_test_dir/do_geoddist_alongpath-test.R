function (lon, lat, a, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_geoddist_alongpath"]][[length(e[["do_geoddist_alongpath"]]) + 
        1]] <- list(lon = lon, lat = lat, a = a, f = f)
    .Call("_oce_do_geoddist_alongpath", lon, lat, a, f)
}
