function (prob, probflight, Xspread, Xbal) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lcubelandingphase"]][[length(e[["lcubelandingphase"]]) + 
        1]] <- list(prob = prob, probflight = probflight, Xspread = Xspread, 
        Xbal = Xbal)
    .Call("_BalancedSampling_lcubelandingphase", PACKAGE = "BalancedSampling", 
        prob, probflight, Xspread, Xbal)
}
