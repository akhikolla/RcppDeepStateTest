function (y, E, a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ldnbinom"]][[length(e[["ldnbinom"]]) + 1]] <- list(y = y, 
        E = E, a = a, b = b)
    .Call("_SpatialEpi_ldnbinom", PACKAGE = "SpatialEpi", y, 
        E, a, b)
}
