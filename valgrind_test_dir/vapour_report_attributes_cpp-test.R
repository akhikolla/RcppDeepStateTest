function (dsource, layer = 0L, sql = "") 
{
    e <- get("data.env", .GlobalEnv)
    e[["vapour_report_attributes_cpp"]][[length(e[["vapour_report_attributes_cpp"]]) + 
        1]] <- list(dsource = dsource, layer = layer, sql = sql)
    .Call("_vapour_vapour_report_attributes_cpp", PACKAGE = "vapour", 
        dsource, layer, sql)
}
