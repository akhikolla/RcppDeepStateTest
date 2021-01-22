function (faces) 
{
    e <- get("data.env", .GlobalEnv)
    e[["expandFacesToEdges_"]][[length(e[["expandFacesToEdges_"]]) + 
        1]] <- list(faces = faces)
    .Call("_icosa_expandFacesToEdges_", faces)
}
