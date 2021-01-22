function (cv1, cv2, cv3, width1, width2, width3, heights, x, 
    y, z, p1, p2, tmin, tmax) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fe3dp12"]][[length(e[["fe3dp12"]]) + 1]] <- list(cv1 = cv1, 
        cv2 = cv2, cv3 = cv3, width1 = width1, width2 = width2, 
        width3 = width3, heights = heights, x = x, y = y, z = z, 
        p1 = p1, p2 = p2, tmin = tmin, tmax = tmax)
    .Call("_metadynminer3d_fe3dp12", PACKAGE = "metadynminer3d", 
        cv1, cv2, cv3, width1, width2, width3, heights, x, y, 
        z, p1, p2, tmin, tmax)
}
