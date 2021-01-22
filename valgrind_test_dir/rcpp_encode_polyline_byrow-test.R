function (longitude, latitude) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_encode_polyline_byrow"]][[length(e[["rcpp_encode_polyline_byrow"]]) + 
        1]] <- list(longitude = longitude, latitude = latitude)
    .Call("_googlePolylines_rcpp_encode_polyline_byrow", PACKAGE = "googlePolylines", 
        longitude, latitude)
}
