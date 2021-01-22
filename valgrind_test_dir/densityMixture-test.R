function (weights, densities) 
{
    e <- get("data.env", .GlobalEnv)
    e[["densityMixture"]][[length(e[["densityMixture"]]) + 1]] <- list(weights = weights, 
        densities = densities)
    .Call("_bsplinePsd_densityMixture", weights, densities)
}
