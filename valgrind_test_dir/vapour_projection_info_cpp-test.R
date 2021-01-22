function (dsource, layer = 0L, sql = "") 
{
    e <- get("data.env", .GlobalEnv)
    e[["vapour_projection_info_cpp"]][[length(e[["vapour_projection_info_cpp"]]) + 
        1]] <- list(dsource = dsource, layer = layer, sql = sql)
    .Call("_vapour_vapour_projection_info_cpp", PACKAGE = "vapour", 
        dsource, layer, sql)
}
