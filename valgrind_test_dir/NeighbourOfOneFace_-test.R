function (faces, faceNo) 
{
    e <- get("data.env", .GlobalEnv)
    e[["NeighbourOfOneFace_"]][[length(e[["NeighbourOfOneFace_"]]) + 
        1]] <- list(faces = faces, faceNo = faceNo)
    .Call("_icosa_NeighbourOfOneFace_", faces, faceNo)
}
