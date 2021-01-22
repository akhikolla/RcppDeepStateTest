function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["normalize"]][[length(e[["normalize"]]) + 1]] <- list(x = x)
    .Call("_SpatialEpi_normalize", PACKAGE = "SpatialEpi", x)
}
