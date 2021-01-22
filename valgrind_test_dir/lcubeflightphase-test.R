function (prob, Xspread, Xbal) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lcubeflightphase"]][[length(e[["lcubeflightphase"]]) + 
        1]] <- list(prob = prob, Xspread = Xspread, Xbal = Xbal)
    .Call("_BalancedSampling_lcubeflightphase", PACKAGE = "BalancedSampling", 
        prob, Xspread, Xbal)
}
