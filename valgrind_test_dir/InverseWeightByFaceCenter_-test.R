function (fcNew, loc, n, fcOld, values, origin, deg) 
{
    e <- get("data.env", .GlobalEnv)
    e[["InverseWeightByFaceCenter_"]][[length(e[["InverseWeightByFaceCenter_"]]) + 
        1]] <- list(fcNew = fcNew, loc = loc, n = n, fcOld = fcOld, 
        values = values, origin = origin, deg = deg)
    .Call("_icosa_InverseWeightByFaceCenter_", fcNew, loc, n, 
        fcOld, values, origin, deg)
}
