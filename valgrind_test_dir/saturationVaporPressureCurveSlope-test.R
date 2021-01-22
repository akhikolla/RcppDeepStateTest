function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["saturationVaporPressureCurveSlope"]][[length(e[["saturationVaporPressureCurveSlope"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
