function (prob, probflight, Xbal) 
{
    e <- get("data.env", .GlobalEnv)
    e[["landingphase"]][[length(e[["landingphase"]]) + 1]] <- list(prob = prob, 
        probflight = probflight, Xbal = Xbal)
    .Call("_BalancedSampling_landingphase", PACKAGE = "BalancedSampling", 
        prob, probflight, Xbal)
}
