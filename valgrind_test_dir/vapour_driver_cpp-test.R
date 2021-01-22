function (dsource) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vapour_driver_cpp"]][[length(e[["vapour_driver_cpp"]]) + 
        1]] <- list(dsource = dsource)
    .Call("_vapour_vapour_driver_cpp", PACKAGE = "vapour", dsource)
}
