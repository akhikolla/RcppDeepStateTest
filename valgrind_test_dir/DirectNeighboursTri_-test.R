function (faces) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DirectNeighboursTri_"]][[length(e[["DirectNeighboursTri_"]]) + 
        1]] <- list(faces = faces)
    .Call("_icosa_DirectNeighboursTri_", faces)
}
