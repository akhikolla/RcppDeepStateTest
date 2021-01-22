function (v0, v1, v2, origin, lineBreak) 
{
    e <- get("data.env", .GlobalEnv)
    e[["TriangleTesselation_"]][[length(e[["TriangleTesselation_"]]) + 
        1]] <- list(v0 = v0, v1 = v1, v2 = v2, origin = origin, 
        lineBreak = lineBreak)
    .Call("_icosa_TriangleTesselation_", v0, v1, v2, origin, 
        lineBreak)
}
