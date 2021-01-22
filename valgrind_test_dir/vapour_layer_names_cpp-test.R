function (dsource, sql = "") 
{
    e <- get("data.env", .GlobalEnv)
    e[["vapour_layer_names_cpp"]][[length(e[["vapour_layer_names_cpp"]]) + 
        1]] <- list(dsource = dsource, sql = sql)
    .Call("_vapour_vapour_layer_names_cpp", PACKAGE = "vapour", 
        dsource, sql)
}
