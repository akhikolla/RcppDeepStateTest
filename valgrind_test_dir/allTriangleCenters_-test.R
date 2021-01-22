function (v, f, origin) 
{
    e <- get("data.env", .GlobalEnv)
    e[["allTriangleCenters_"]][[length(e[["allTriangleCenters_"]]) + 
        1]] <- list(v = v, f = f, origin = origin)
    .Call("_icosa_allTriangleCenters_", v, f, origin)
}
