function (lon, lat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pz_hemisphere"]][[length(e[["pz_hemisphere"]]) + 1]] <- list(lon = lon, 
        lat = lat)
    .Call("_parzer_pz_hemisphere", PACKAGE = "parzer", lon, lat)
}
