function (edges) 
{
    e <- get("data.env", .GlobalEnv)
    e[["EdgesToFaces_"]][[length(e[["EdgesToFaces_"]]) + 1]] <- list(edges = edges)
    .Call("_icosa_EdgesToFaces_", edges)
}
