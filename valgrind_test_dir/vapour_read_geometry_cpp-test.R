function (dsource, layer = 0L, sql = "", what = "geometry", textformat = "json", 
    limit_n = 0L, skip_n = 0L, ex = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vapour_read_geometry_cpp"]][[length(e[["vapour_read_geometry_cpp"]]) + 
        1]] <- list(dsource = dsource, layer = layer, sql = sql, 
        what = what, textformat = textformat, limit_n = limit_n, 
        skip_n = skip_n, ex = ex)
    .Call("_vapour_vapour_read_geometry_cpp", PACKAGE = "vapour", 
        dsource, layer, sql, what, textformat, limit_n, skip_n, 
        ex)
}
