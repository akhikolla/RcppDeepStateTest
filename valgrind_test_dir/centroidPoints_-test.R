function (coords, combin, center, breaks) 
{
    e <- get("data.env", .GlobalEnv)
    e[["centroidPoints_"]][[length(e[["centroidPoints_"]]) + 
        1]] <- list(coords = coords, combin = combin, center = center, 
        breaks = breaks)
    .Call("_icosa_centroidPoints_", coords, combin, center, breaks)
}
