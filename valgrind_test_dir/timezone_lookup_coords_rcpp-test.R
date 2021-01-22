function (latv, lonv) 
{
    e <- get("data.env", .GlobalEnv)
    e[["timezone_lookup_coords_rcpp"]][[length(e[["timezone_lookup_coords_rcpp"]]) + 
        1]] <- list(latv = latv, lonv = lonv)
    .Call("_lutz_timezone_lookup_coords_rcpp", latv, lonv)
}
