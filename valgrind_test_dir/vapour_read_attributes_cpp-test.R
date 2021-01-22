function (dsource, layer = 0L, sql = "", limit_n = 0L, skip_n = 0L, 
    ex = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vapour_read_attributes_cpp"]][[length(e[["vapour_read_attributes_cpp"]]) + 
        1]] <- list(dsource = dsource, layer = layer, sql = sql, 
        limit_n = limit_n, skip_n = skip_n, ex = ex)
    .Call("_vapour_vapour_read_attributes_cpp", PACKAGE = "vapour", 
        dsource, layer, sql, limit_n, skip_n, ex)
}
