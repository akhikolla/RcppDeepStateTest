function (prob, Xbal) 
{
    e <- get("data.env", .GlobalEnv)
    e[["flightphase"]][[length(e[["flightphase"]]) + 1]] <- list(prob = prob, 
        Xbal = Xbal)
    .Call("_BalancedSampling_flightphase", PACKAGE = "BalancedSampling", 
        prob, Xbal)
}
