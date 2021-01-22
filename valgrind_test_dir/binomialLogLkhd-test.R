function (cz, nz, N, C) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binomialLogLkhd"]][[length(e[["binomialLogLkhd"]]) + 
        1]] <- list(cz = cz, nz = nz, N = N, C = C)
    .Call("_SpatialEpi_binomialLogLkhd", PACKAGE = "SpatialEpi", 
        cz, nz, N, C)
}
