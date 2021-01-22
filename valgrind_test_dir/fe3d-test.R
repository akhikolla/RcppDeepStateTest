function (cv1, cv2, cv3, width1, width2, width3, heights, x, 
    y, z, tmin, tmax) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fe3d"]][[length(e[["fe3d"]]) + 1]] <- list(cv1 = cv1, 
        cv2 = cv2, cv3 = cv3, width1 = width1, width2 = width2, 
        width3 = width3, heights = heights, x = x, y = y, z = z, 
        tmin = tmin, tmax = tmax)
    .Call("_metadynminer3d_fe3d", PACKAGE = "metadynminer3d", 
        cv1, cv2, cv3, width1, width2, width3, heights, x, y, 
        z, tmin, tmax)
}
