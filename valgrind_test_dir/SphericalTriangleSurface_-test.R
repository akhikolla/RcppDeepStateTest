function (coord1, coord2, coord3, origin, pi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SphericalTriangleSurface_"]][[length(e[["SphericalTriangleSurface_"]]) + 
        1]] <- list(coord1 = coord1, coord2 = coord2, coord3 = coord3, 
        origin = origin, pi = pi)
    .Call("_icosa_SphericalTriangleSurface_", coord1, coord2, 
        coord3, origin, pi)
}
