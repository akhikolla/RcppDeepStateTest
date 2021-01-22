function (allFaces, div) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AllNeighboursTri_"]][[length(e[["AllNeighboursTri_"]]) + 
        1]] <- list(allFaces = allFaces, div = div)
    .Call("_icosa_AllNeighboursTri_", allFaces, div)
}
