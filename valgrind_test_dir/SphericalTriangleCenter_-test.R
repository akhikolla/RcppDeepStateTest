function (v0, v1, v2, origin) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SphericalTriangleCenter_"]][[length(e[["SphericalTriangleCenter_"]]) + 
        1]] <- list(v0 = v0, v1 = v1, v2 = v2, origin = origin)
    .Call("_icosa_SphericalTriangleCenter_", v0, v1, v2, origin)
}
