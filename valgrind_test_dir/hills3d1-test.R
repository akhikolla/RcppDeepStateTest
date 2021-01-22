function (cv1, cv2, cv3, width1, width2, width3, heights, n, 
    tmin, tmax) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hills3d1"]][[length(e[["hills3d1"]]) + 1]] <- list(cv1 = cv1, 
        cv2 = cv2, cv3 = cv3, width1 = width1, width2 = width2, 
        width3 = width3, heights = heights, n = n, tmin = tmin, 
        tmax = tmax)
    .Call("_metadynminer3d_hills3d1", PACKAGE = "metadynminer3d", 
        cv1, cv2, cv3, width1, width2, width3, heights, n, tmin, 
        tmax)
}
