function (oldV, oldF, tesselation, origin) 
{
    e <- get("data.env", .GlobalEnv)
    e[["IcosahedronTesselation_"]][[length(e[["IcosahedronTesselation_"]]) + 
        1]] <- list(oldV = oldV, oldF = oldF, tesselation = tesselation, 
        origin = origin)
    .Call("_icosa_IcosahedronTesselation_", oldV, oldF, tesselation, 
        origin)
}
