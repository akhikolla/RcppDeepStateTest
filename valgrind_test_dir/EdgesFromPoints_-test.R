function (verts, howMany, origin) 
{
    e <- get("data.env", .GlobalEnv)
    e[["EdgesFromPoints_"]][[length(e[["EdgesFromPoints_"]]) + 
        1]] <- list(verts = verts, howMany = howMany, origin = origin)
    .Call("_icosa_EdgesFromPoints_", verts, howMany, origin)
}
