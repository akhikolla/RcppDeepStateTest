function (faces, neigh, startFaces, startVert, nBelts, nV) 
{
    e <- get("data.env", .GlobalEnv)
    e[["orderTriGrid_"]][[length(e[["orderTriGrid_"]]) + 1]] <- list(faces = faces, 
        neigh = neigh, startFaces = startFaces, startVert = startVert, 
        nBelts = nBelts, nV = nV)
    .Call("_icosa_orderTriGrid_", faces, neigh, startFaces, startVert, 
        nBelts, nV)
}
