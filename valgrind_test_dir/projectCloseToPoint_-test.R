function (coords, toPoint, center, breaks) 
{
    e <- get("data.env", .GlobalEnv)
    e[["projectCloseToPoint_"]][[length(e[["projectCloseToPoint_"]]) + 
        1]] <- list(coords = coords, toPoint = toPoint, center = center, 
        breaks = breaks)
    .Call("_icosa_projectCloseToPoint_", coords, toPoint, center, 
        breaks)
}
