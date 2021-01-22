function (X, coef, h, t, type, trimLo, trimUp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["computeMSPEcpp"]][[length(e[["computeMSPEcpp"]]) + 1]] <- list(X = X, 
        coef = coef, h = h, t = t, type = type, trimLo = trimLo, 
        trimUp = trimUp)
    .Call("_forecastSNSTS_computeMSPEcpp", PACKAGE = "forecastSNSTS", 
        X, coef, h, t, type, trimLo, trimUp)
}
