function (outN) 
{
    e <- get("data.env", .GlobalEnv)
    e[["edgeListFromNeighbours_"]][[length(e[["edgeListFromNeighbours_"]]) + 
        1]] <- list(outN = outN)
    .Call("_icosa_edgeListFromNeighbours_", outN)
}
