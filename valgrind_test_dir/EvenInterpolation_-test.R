function (xyz, origin, critValue) 
{
    e <- get("data.env", .GlobalEnv)
    e[["EvenInterpolation_"]][[length(e[["EvenInterpolation_"]]) + 
        1]] <- list(xyz = xyz, origin = origin, critValue = critValue)
    .Call("_icosa_EvenInterpolation_", xyz, origin, critValue)
}
