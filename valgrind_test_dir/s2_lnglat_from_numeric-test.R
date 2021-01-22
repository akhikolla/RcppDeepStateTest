function (lng, lat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["s2_lnglat_from_numeric"]][[length(e[["s2_lnglat_from_numeric"]]) + 
        1]] <- list(lng = lng, lat = lat)
    .Call("_s2_s2_lnglat_from_numeric", lng, lat)
}
