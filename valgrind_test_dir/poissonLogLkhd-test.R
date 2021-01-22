function (cz, nz, N, C) 
{
    e <- get("data.env", .GlobalEnv)
    e[["poissonLogLkhd"]][[length(e[["poissonLogLkhd"]]) + 1]] <- list(cz = cz, 
        nz = nz, N = N, C = C)
    .Call("_SpatialEpi_poissonLogLkhd", PACKAGE = "SpatialEpi", 
        cz, nz, N, C)
}
